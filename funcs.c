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
    int flag = 0;
    if (num[1] == '-')
    {	
	num += 1;
	flag = 1;
    }
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
    if(flag == 1)
    {
	result = result*(-1);
    }
    return result;
}

char* tenbin(int x)
{
    char* str = NULL;
    int num = abs(x);
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }
    if(x >= 0)
    	snprintf(str, sizeof str, "%d", bin);
    else
	snprintf(str,sizeof str, "-%d", bin);
    return str;


}

char* tenoct(int x)
{
    int num = abs(x);
    char* str = NULL;
    int oct = 0,k = 1;

    while(num)
    {
	oct += (num % 8) * k;
	k *= 10;
	num /= 8;
    }
    if(x >= 0)
    {
       sprintf(str,"0%d",oct);
    }
    else
    {
	sprintf(str,"-0%d",oct);
    }
    return str;
}

char* tenhex(int num)
{
    char* hex;

    if(num >= 0)
    {
    	sprintf(hex, "0x%X", num); 
    }
    else
    {	
	sprintf(hex,"-0x%X",abs(num));
    }
    return hex;

}

int prost(int num1, int num2,char* oper)
{
   
	if (oper[0] == '+')
		return num1 + num2;
	else if(oper[0] == '-')
		return num1 - num2;
	else if(oper[0] == '*')
		return num1*num2;
	else if(oper[0] == '%')
		return abs(num1) % abs(num2);
	else if(oper[0] == '&')
	{
	    if(num1 < 0 || num2 < 0)
	    {
		printf("ERROR all number should be above zero\n");
   		exit(-1);
	    }
	    return num1 & num2;
	}
	else if(oper[0] == '|')
	{
	    if(num1 < 0 || num2 < 0)
	    {
		printf("ERROR all number should be above zero\n");
		exit(-1);
	    }
	    return num1 | num2; 
	}
	else if(oper[0] == '^')
	{
	    if(num1 < 0 || num2 < 0)
	    {
		printf("ERROR all number should be above zero\n");
		exit(-1);
	    }
	    return num1 ^ num2;
	}
	else
	{
	    printf("ERROR Unknown operation\n");
	    exit(-1);
	}

	
    }
}


char* operation(char* num1, char* num2, char* oper)
{
    if(num1[0] == '0' && num2[0] == '0')
    {
	if(num1[1] == 'x' && num2[1] == 'x')
	{
	    int x = toten(num1,16);
	    int y = toten(num2,16);

	    int result = prost(x,y,oper);
	    char *str = tenhex(result);
	    return str;
	}
	else if((num1[1] == 'x' && num2[1] != 'x') || (num1[1] != 'x' && num2[1] == 'x'))
	{
	     printf("Error Not same sist\n");
	     exit(-1);
	}
	else if(num1[1] != 'x' && num2[1] != 'x')
	{
	    int x = toten(num1,8);
	    int y = toten(num2,8);

	    int result = prost(x,y,oper);
	    char *str = tenoct(result);

	    return str;
	}
    }
    else
    {
	int x = toten(num1,2);
	int y = toten(num2,2);

	int result = prost(x,y,oper);

	char *str = tenbin(result);

	return str;
    }
}	
