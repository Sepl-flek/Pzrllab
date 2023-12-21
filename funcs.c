#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <math.h>
#include <string.h>

int toten(char* num,int base, int count)
{
    //int len = strlen(num);
    int power = 1;
    int result = 0;
    int flag = 0;
    if (num[0] == '-')
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
    for (int i = len - 1 - count; i >= 0; i--) {
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

char *tenbin(int decimalNumber) {
    // Проверка на ноль
    if (decimalNumber == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    // Обработка отрицательных чисел
    int isNegative = 0;
    if (decimalNumber < 0) {
        isNegative = 1;
        decimalNumber = -decimalNumber;
    }

    char binaryStr[33]; // Максимальная длина для типа int - 32 бита
    int index = 0;
    while (decimalNumber > 0) {
        binaryStr[index] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
        index++;
    }
    binaryStr[index] = '\0'; // Добавляем нуль-терминатор

    // Переворачиваем строку, чтобы получить правильный порядок цифр
    int length = strlen(binaryStr);
    for (int i = 0; i < length / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[length - i - 1];
        binaryStr[length - i - 1] = temp;
    }

    if (isNegative) {
        char* result = (char*)malloc((strlen(binaryStr) + 2) * sizeof(char));
        result[0] = '-';
        strcpy(&result[1], binaryStr);
        return result;
    } else {
        char* result = (char*)malloc((strlen(binaryStr) + 1) * sizeof(char));
        strcpy(result, binaryStr);
        return result;
    }
}

char *tenoct(int decimalNumber) {
    char *octalNumber = (char *)malloc(30 * sizeof(char));  // максимальная длина восьмеричного числа для int - 11 символов плюс минус и нуль-терминатор
    octalNumber[0] = '\0';  // обнуляем строку
    int hasMinus = 0; // флаг для отслеживания отрицательных чисел

    if (decimalNumber == 0) {
        strcpy(octalNumber, "00");  // если число равно 0, то результат - "0"
        return octalNumber;
    }

    if (decimalNumber < 0) {
        hasMinus = 1; // устанавливаем флаг и делаем число положительным
        decimalNumber = -decimalNumber;
    }
    
    int num = decimalNumber;  // получаем абсолютное значение числа
    int index = 0;
    while (num > 0) {
        octalNumber[index] = (num % 8) + '0';  // конвертируем в символ
        num /= 8;
        index++;
    }

    if (hasMinus) {
        octalNumber[index] = '0';
        index++;
    }

    octalNumber[index] = '\0';  // добавляем нуль-терминатор

    // переворачиваем строку, чтобы получить правильный порядок цифр
    int length = strlen(octalNumber);
    for (int i = 0; i < length / 2; i++) {
        char temp = octalNumber[i];
        octalNumber[i] = octalNumber[length - i - 1];
        octalNumber[length - i - 1] = temp;
    }

    if (hasMinus) {
        // смещаем минус в начало, а нуль заменяем на пустую строку
        memmove(&octalNumber[1], &octalNumber[0], length + 1);
        octalNumber[0] = '-';
    }

    return octalNumber;
}

char *tenhex(int decimalNumber) {
    if (decimalNumber == 0) {
        char *result = (char *)malloc(10 * sizeof(char));
        strcpy(result, "0x0");  // если число равно 0, то результат - "0x0"
        return result;
    }

    int isNegative = 0;
    if (decimalNumber < 0) {
        isNegative = 1;
        decimalNumber = -decimalNumber;
    }

    char hexStr[20]; // Максимальная длина для типа int - 10 символов
    int index = 0;
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexStr[index] = remainder + '0';
        } else {
            hexStr[index] = 'A' + (remainder - 10);  // диапазон букв A-F для шестнадцатеричных чисел
        }
        decimalNumber /= 16;
        index++;
    }

    

    hexStr[index] = 'x';
    index++;
    hexStr[index] = '0';
    index++;
    hexStr[index] = '\0';

    // Переворачиваем строку, чтобы получить правильный порядок цифр
    int length = strlen(hexStr);
    for (int i = 0; i < length / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[length - i - 1];
        hexStr[length - i - 1] = temp;
    }

    char *result;
    if (isNegative) {
        result = (char *)malloc((strlen(hexStr) + 1) * sizeof(char));
        strcpy(&result[1], hexStr);
        result[0] = '-';
    } else {
        result = (char *)malloc(strlen(hexStr) * sizeof(char));
        strcpy(result, hexStr);
    }

    return result;
}

int prost(int num1, int num2,char *oper)
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

void operation(char* num1, char* num2, char *oper)
{
    if(num1[0] == '0' && num2[0] == '0')
    {
	if(num1[1] == 'x' && num2[1] == 'x')
	{
	    int x = toten(num1,16, 0);
	    int y = toten(num2,16, 1);

	    int result = prost(x,y,oper);
	    char *str = tenhex(result);
	    printf("%s (%d)\n",str,result);
	    exit(0);
	}
	else if((num1[1] == 'x' && num2[1] != 'x') || (num1[1] != 'x' && num2[1] == 'x'))
	{
	     printf("Error Not same sist\n");
	     exit(-1);
	}
	else if(num1[1] != 'x' && num2[1] != 'x')
	{
	    int x = toten(num1,8, 0);
	    int y = toten(num2,8, 1);

	    if(x == 0 && y == 0)
	    {
		printf("0 (0)\n");
		exit(0);
	    }   

	    int result = prost(x,y,oper);
	    char *str = tenoct(result);

	    printf("%s (%d)\n",str,result);
	    exit(0);
	}
    }
    else
    {
	if (num1[0] == '0' || num2[0] == '0')
	{
	     printf("ERROR Not same sist\n");
	     exit(-1);
	}
	int x = toten(num1,2, 0);
	int y = toten(num2,2, 1);
	

	int result = prost(x,y,oper);

	char *str = tenbin(result);
	printf("%s (%d)\n",str,result);

	exit(0);	
	//return str;
    }
}	
