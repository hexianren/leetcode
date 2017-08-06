#include <stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int i = 0, max = 0;
	int tmp = 0;
	int flag = 0;
	if (nums == NULL || numsSize == 0) {
		return 0;
	}
	
	if (numsSize == 1) {
	    if (nums[i] == 1) {
	        return 1;
	    } else {
	        return 0;
	    }
	}

	for (i = 0;i < numsSize;i++) {
		if (nums[i] == 0) {
			if (tmp == 0 && flag == 0) {
				flag = 1;
				max = i;
				tmp = i;
			} else {
				max = (max > (i - tmp - 1)) ? max : (i - tmp - 1);
				tmp = i;
			}
		}
	}

	if (tmp == 0) {
		return numsSize;
	}
	max = (max > (numsSize - 1 - tmp)) ? max : (numsSize - 1 - tmp);
	return max;
}

int main(void)
{
	int array[] = {0,1};
	int a = findMaxConsecutiveOnes(array, 2);
	printf("%d\n", a);
	return 0;
}