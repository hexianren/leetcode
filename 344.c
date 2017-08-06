#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

char* reverseString(char* s) {
	if (s == NULL) {
		return NULL;
	}
    int size = strlen(s);
    if (size == 0) {
    	return "";
    }
    char *result = (char*) malloc(sizeof(char) * (size + 1));
    memset(result ,0, size + 1);
    int i = 0;
    for (i = 0;i < size;i++) {
    	result[i] = s[size - i - 1];
    }
    return result;
}

int main(void)
{
	char *result = reverseString("hello");
	printf("%s\n", result);
	free(result);
	return 0;
}