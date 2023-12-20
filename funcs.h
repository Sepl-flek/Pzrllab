#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int toten(char* num, int base);

char* tenbin(int x);
char* tenhex(int num);
char* tenoct(int x);


char* operation(char* num1, char* num2, char* oper);

