#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int		val;
	struct ListNode *next;
};
struct ListNode *
addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	int	temp = 0,	flag = 0;
	struct ListNode *result = NULL, *head = NULL;

	while (l1 != NULL && l2 != NULL) {
		if (result == NULL) {
			head = result = (struct ListNode *)malloc(sizeof(struct ListNode));
			result->next = NULL;
		} else {
			result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			result = result->next;
			result->next = NULL;
		}

		if (l1 == NULL) {
			result->val = l2->val + flag;
			l2 = l2->next;
		} else if (l2 == NULL) {
			result->val = l1->val + flag;
			l1 = l1->next;
		} else {
			temp = l1->val + l2->val + flag;
			if (temp > 9) {
				flag = 1;
			} else {
				flag = 0;
			}
			result->val = temp - 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (flag) {
			result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			result->val = 1;
			result->next = NULL;
		}
	}

	return head;
}

int
main(void)
{
	struct ListNode *result = NULL, *l1 = NULL, *l2 = NULL;
	l1 = result = (struct ListNode *)malloc(sizeof(struct ListNode));
	result->val = 2;

	result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	result = result->next;
	result->val = 4;

	result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	result = result->next;
	result->val = 2;
	result->next = NULL;

	l2 = result = (struct ListNode *)malloc(sizeof(struct ListNode));
	result->val = 5;

	result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	result = result->next;
	result->val = 6;

	result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	result = result->next;
	result->val = 4;
	result->next = NULL;
	struct ListNode *haha = addTwoNumbers(l1, l2);
	while(haha != NULL) {
		printf("%d\n", haha->val);
		haha = haha->next;
	}

	return 0;
}
