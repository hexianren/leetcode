#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* addBinary(char* a, char* b) {
	if (a == NULL || b == NULL) {
		return NULL;
	}

	int tmp_result_length = 0;
	int a_length = 0;
	int b_length = 0;
	int flag = 0;
	int i = 0;
	//有1的标志位
	int one_flag = 0;
	char *tmp_result, *tmp_a, *tmp_b, *result;

	a_length = strlen(a);
	b_length = strlen(b);
	tmp_result_length = (a_length > b_length ? a_length + 2 : b_length + 2);
	tmp_result = (char*) malloc(tmp_result_length * sizeof(char));

	tmp_a = (char*)malloc(tmp_result_length * sizeof(char));
	tmp_b = (char*)malloc(tmp_result_length * sizeof(char));

	memset(tmp_result, '0', tmp_result_length * sizeof(char));
	tmp_result[tmp_result_length - 1] = '\0';
	memset(tmp_a, 0, tmp_result_length * sizeof(char));
	memset(tmp_b, 0, tmp_result_length * sizeof(char));

	strcpy(tmp_a + (tmp_result_length - a_length - 1), a);
	strcpy(tmp_b + (tmp_result_length - b_length - 1), b);


	int sum = 0;
	for (i = tmp_result_length - 2;i >= 0;i--) {
		if (tmp_a[i] != '\0' && tmp_b[i] != '\0') {
			sum = (tmp_a[i] - '0') + (tmp_b[i] - '0') + flag;
		} else if (tmp_a[i] == '\0' && tmp_b[i] != '\0') {
			sum = (tmp_b[i] - '0') + flag;
		} else if (tmp_a[i] != '\0' && tmp_b[i] == '\0') {
			sum = (tmp_a[i] - '0') + flag;
		} else if (tmp_a[i] == '\0' && tmp_b[i] == '\0') {
			sum = flag;
		}
		if (sum == 0) {
			tmp_result[i] = '0';
			flag = 0;
		} else if (sum == 1) {
			tmp_result[i] = '1';
			flag = 0;
		} else if (sum == 2) {
			tmp_result[i] = '0';
			flag = 1;
		} else if (sum == 3) {
			tmp_result[i] = '1';
			flag = 1;
		}
	}

	for (i = 0;i < tmp_result_length;i++) {
		if (tmp_result[i] == '1') {
			one_flag = 1;
			break;
		}
	}
	
	if (!one_flag) {
		result = (char*)malloc(2 * sizeof(char));
		memset(result, 0, 2);
		strcpy(result, "0");
	} else {
		result = (char*)malloc((tmp_result_length - i) * sizeof(char));
		memset(result, 0, (tmp_result_length - i));
		strcpy(result, &(tmp_result[i]));
		
	}
	free(tmp_a);
	free(tmp_b);
	return result;
}

int main(void)
{
	char *tmp_result = addBinary("101", "1");
	printf("%s\n", tmp_result);
	free(tmp_result);
	return 0;
}