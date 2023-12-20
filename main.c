#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char** argv)
{
    char *num = NULL;
    size_t size = 0;
    getline(&num, &size,stdin);
    char* arr[sizeof(num)];
    char* token = strtok(num," ");
    char *oper;
    

    int i = 0;

    while(token != NULL)
    {
	arr[i++] = token;
	token = (NULL," ");
    }

    if(i == 2 || i >= 4)
    {
	printf("ERROR");
	return -1;
    }

    if(i == 1 && arr[0][0] == 126 && arr[0][1] != 45)
    {
	//function ~
    }
    else if(i == 3)
    {
	char* num1 = arr[0];
	oper = arr[1];
	char* num2 = arr[2];
	operation(num1,num2,oper);
    }
   
        

    
    
    return 0;
}
