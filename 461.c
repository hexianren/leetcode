#include <stdio.h>
int 
hammingDistance(int x, int y)
{
	int		xor = x ^ y;
	int		i = 0;
	int		result = 0;
	for (i = 0; i < 32; i++) {
		if ((xor & (1 << i))) {
			result++;
		}
	}
	return result;
}

int 
main(void)
{
	printf("%d\n", hammingDistance(1, 4));
	return 0;
}
