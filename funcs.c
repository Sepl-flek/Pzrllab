#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <math.h>
#include <string.h>

int toten(char* num,int base)
{
    //int len = strlen(num);
    int power = 1;
    int result = 0;
    if(base == 8)
    {
	num++;
    }
    if(base == 16)
    {
	num += 2;
    }
    int len = strlen(num);
    for (int i = len - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else {
            digit = num[i] - 'A' + 10;
        }
        result += digit * power;
        power *= base;
    }

    return result;
}

char* tenbin(int num)
{
    char* str = NULL;

    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }
    snprintf(str, sizeof str, "%d", bin);
    return str;


}

char* tenoct(int num)
{
    char* str = NULL;
    int oct = 0,k = 1;

    while(num)
    {
	oct += (num % 8) * k;
	k *= 10;
	num /= 8;
    }
    sprintf(str,"0%d",num);
    return str;
}

char* tenhex(int num)
{
    char* hex;

    sprintf(hex, "%X", num); 

    return hex;

}
