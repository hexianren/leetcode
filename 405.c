#include <stdio.h>
#include <string.h>

char retChar(int ch)
{
	switch (ch) {
		case 0: return '0';
		case 1: return '1';

		case 2: return '2';

		case 3: return '3';

		case 4: return '4';

		case 5: return '5';

		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 0xa: return 'a';
		case 0xb: return 'b';
		case 0xc: return 'c';
		case 0xd: return 'd';
		case 0xe: return 'e';
		case 0xf: return 'f';
	}
	return '\0';
}

char result[10];

char* toHex(int num) {
	int isNav = 0;
    
    	num = (unsigned int)num;
    

    memset(result, 0, 10);
    char numChar[8] = {'\0'};
    int i = 0;
    int temp = 0;
    for (i = 0;i < 8;i++) {
    	temp = (num >> (i * 4)) & 0xf;
    	//printf("%d\n", temp);
    	numChar[7 - i] = retChar(temp);
    }
    for (i = 0;i < 7;i++) {
    	if (numChar[i] != '0') {
    		break;
    	}		
    }
    //if (isNav) {
    //	result[0] = '-';
    //	memcpy(result + 1, numChar + i, 8 - i);
    //} else {
    	memcpy(result, numChar + i, 8 - i);
    //}
    return result;
}

int main(void)
{
	printf("%s\n", toHex(0));
	return 0;
}