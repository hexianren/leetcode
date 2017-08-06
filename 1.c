#include <stdio.h>
#include <string.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	if (numsSize < 2 && nums == NULL) {
		return NULL;
	}
	int flag = 0;
	int *result = (int*) malloc(2 * sizeof(int));
	memset(result, 0 , sizeof(int) * 2);
    int i = 0, j = 0;
    for (i = 0;i < numsSize;i++) {
    	for (j = i + 1;j < numsSize;j++) {
    		if (nums[i] + nums[j] == target) {
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) {
    		break;
    	}
    }
    result[0] = i;
    result[1] = j;
    return result;
}

int main(void)
{
	int nums[] = {3,2,4};
	int *result = twoSum(nums, 3, 6);
	printf("%d %d\n", result[0], result[1]);

	return 0;
}