#include <stdio.h>

int findComplement(int num) {
    int i = 0;
    int tmp = num;
    if (num == 0) {
        return 1;
    }
    while(num != 0) {
        num /= 2;
        i++;
    }
    return (1 << i) - 1 - tmp;
}

int main(void)
{
	printf("%d\n", findComplement(2));
	return 0;
}