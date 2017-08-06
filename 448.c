#include <stdio.h>
#include <stdlib.h>
//这道题解题思路很巧妙
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize <= 0) {
    	return NULL;
    }

    int i = 0;
    int value = 0;
    int okCount = 0;
    int count = 0;
    for (i = 0;i < numsSize;i++) {
    	value = abs(nums[i]);

    	if (value - 1 >= 0 && value - 1 < numsSize) {

    		if (nums[value - 1] >= 0) {
    			nums[value - 1] = -((nums[value - 1]));
    			//printf("%d\n", nums[value - 1]);
    			okCount++;
    		}
    		
    	}
    	
    }

    *returnSize = (numsSize - okCount);
    int *result = (int*)malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < numsSize; i++) {
    	if (nums[i] > 0) {
    		result[count] = i + 1;
    		count++;
    	}
    }
    return result;
}

int main(void)
{
	int size = 0;
	int array[] = {4,3,2,7,8,2,3,1};
	int *result = findDisappearedNumbers(array, 8, &size);
	if (result != NULL) {
		for (int i = 0; i < size;i++) {
			//printf("%d\n", result[i]);
		}
	}
	return 0;
}