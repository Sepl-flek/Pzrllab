#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int toten(char* num, int base, int count);

char* tenbin(int decimalNumber);
char* tenhex(int decimalNumber);
char* tenoct(int decimalNumber);


void operation(char* num1, char* num2, char* oper);

int prost(int num1, int num2, char* oper);

void tild(char* num);
