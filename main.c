#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main()
{
    	
    char input[200];

    fgets(input, 200, stdin);

    char *arr[100]; 

    char *token = strtok(input, " "); 
    
    int i = 0;
    char* num1;
    char* num2;


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
	tild(arr[0]);
    }
    else if(i == 3)
    {
	num1 = arr[0];
	strcpy(oper, arr[1]);
	
	num2 = arr[2];
	operation(num1,num2,oper);
	free(num1);
	free(num2);


	//strcpy(str,operation(num1,num2,oper));
	//printf("%s\n",str);
	//free(str);
    }
  free(num1);
  free(num2); 
  
  free(token);
//  free(input);
 
  for(int i = 0; i < 100; ++i)
  {
	  free(arr[i]);
  }  
    
    return 0;
}
