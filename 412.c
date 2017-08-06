#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **result = (char**) (malloc(sizeof(char*) * n));
    const int SIZE = 32;
    for (int i = 1; i <= n;i++) {
    	if (i % 3 == 0 && i % 5 != 0) {
    		result[i] = (char*) malloc(sizeof(char) * SIZE);
    		strcpy(result[i], "Fizz");
    	} else if (i % 3 != 0 && i % 5 == 0) {
    		result[i] = (char*) malloc(sizeof(char) * SIZE);
    		strcpy(result[i], "Buzz");
    	} else if (i % 3 == 0 && i % 5 == 0) {
    		result[i] = (char*) malloc(sizeof(char) * SIZE);
    		strcpy(result[i], "FizzBuzz");
    	} else {
    		result[i] = (char*) malloc(sizeof(char) * SIZE);
    		sprintf(result[i], "%d", i);
    	}
    }
	for (int i = 1;i <= n;i++) {
		printf("%s\n", result[i]);
	}
    *returnSize = n;
    return result;
}

int main(void)
{
	int size;
	char **result = fizzBuzz(5, &size);
	
	//free(result);
	return 0;
}