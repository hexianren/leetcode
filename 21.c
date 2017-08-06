#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	int isToLow = 0;
	struct ListNode* result = NULL;
    if (l1 == NULL && l2 == NULL) {
    	return NULL;
    }

    if (l1 == NULL && l2 != NULL) {
    	return l2;
    }

    if (l1 != NULL && l2 == NULL) {
    	return l1;
    }

    if (l1->next != NULL) {
    	isToLow = l1->val > l1->next->val ? 1 : 0;
    } else if (l2->next != NULL) {
    	isToLow = l2->val > l2->next->val ? 1 : 0;
    }

    if (isToLow) {
    	while(l1 != NULL && l2 != NULL) {
    		if (result == NULL)  {
    			if (l1->val > l2->val) {
    				result = l1;
    				l1 = l1->next;
    			} else {
    				result = l2;
    				l2 = l2->next;
    			}
    			continue;
    		}

    		if (l1 == NULL) {
    			result->next = l2;
    			return result;
    		}

    		if (l2 == NULL) {
    			result->next = l1;
    			return result;
    		}

    		if (l1->val > l2->val) {
    			result->next = l1;
    			l1 = l1->next;
    			result = result->next;
    		}
    		if (l1->val < l2->val) {
    			result->next = l2;
    			l2 = l2->next;
    			result = result->next;
    		}
    	}
    }

    if (!isToLow) {
    	while(l1 != NULL && l2 != NULL) {
    		if (result == NULL)  {
    			if (l1->val < l2->val) {
    				result = l1;
    				l1 = l1->next;
    			} else {
    				result = l2;
    				l2 = l2->next;
    			}
    			continue;
    		}

    		if (l1 == NULL) {
    			result->next = l2;
    			return result;
    		}

    		if (l2 == NULL) {
    			result->next = l1;
    			return result;
    		}
    		if (l1->val < l2->val) {
    			result->next = l1;
    			l1 = l1->next;
    			result = result->next;
    		}
    		if (l1->val > l2->val) {
    			result->next = l2;
    			l2 = l2->next;
    			result = result->next;
    		}
    	}
    }
    return result;
}

int main(void)
{
	struct ListNode *l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
	l1->val = -9;
	l1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
	l1->next->val = 3;
	l1->next->next = NULL;
	struct ListNode *l2 = (struct ListNode*) malloc(sizeof(struct ListNode));
	l2->val = 5;
	l2->next = (struct ListNode*) malloc(sizeof(struct ListNode));
	l2->next->val = 7;
	l2->next->next = NULL;

	mergeTwoLists(l1, l2);
	return 0;
}