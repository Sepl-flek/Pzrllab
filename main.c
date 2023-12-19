#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char** argv)
{
    char num[] = "0x1A7";
    int base = 16;
    int result = toten(num, base);
    printf("%d\n",result);
   
    return 0;
}
