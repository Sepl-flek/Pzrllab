#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char** argv)
{
    	
    char input[1000];

    fgets(input, 1000, stdin);

    char *arr[100]; 

    char *token = strtok(input, " "); 
    
    int i = 0;

    char oper[10];

    while (token != NULL) {

        if(isdigit(token[0]) == 0){

            strcpy(oper, token);
        }

        arr[i++] = token; 

        token = strtok(NULL, " ");

    
    }

    if(i == 2 || i >= 4)
    {
	printf("ERROR\n");
	return -1;
    }

    if(i == 1 && arr[0][0] == 126 && arr[0][1] != 45)
    {
	printf("Yes\n");
	tild(arr[0]);
    }
    else if(i == 3)
    {
	char* num1 = malloc(1000);
	num1 = arr[0];
	strcpy(oper, arr[1]);
	char* num2 = malloc(1000);
	num2 = arr[2];
	operation(num1,num2,oper);


	//strcpy(str,operation(num1,num2,oper));
	//printf("%s\n",str);
	//free(str);
    }
   
  
  free(token);
    
    
    return 0;
}
