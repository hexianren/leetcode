#include <stdio.h>
#include <strings.h>

int isAnagram(char* s, char* t) {
	int i;
	char temp;
	int s_num[26] = {0};
	int t_num[26] = {0};
	if (s == NULL && t == NULL)  {
		return 1;
	}
	int s_lenght = strlen(s);   
	int t_lenght = strlen(t);
	if (s_lenght == 0 && t_lenght == 0) {
		return 1;
	}
	if (s_lenght != t_lenght) {
		return 0;
	}

	for (i = 0;i < s_lenght;i++) {
		temp = s[i];
		s_num[temp - 'a']++;
	}

	for (i = 0;i < t_lenght;i++) {
		temp = t[i];
		t_num[temp - 'a']++;
	}

	for (i = 0;i < 26;i++) {
		if (s_num[i] != t_num[i]) {
			return 0;
		}
	}

	return 1;
}

int main(void)
{
	printf("%d\n", isAnagram("a", "a"));	
	return 0;
}