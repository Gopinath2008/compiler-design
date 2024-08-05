#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char input[MAX]; 
int index = 0;   
int tempCount = 0; 
void genTAC(char *op, char *arg1, char *arg2);
void E();
void T();
void F();
void parse();
int main()
{
    printf("Enter the expression (only +, -, *, /, ID, NUM, and parentheses are allowed): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    printf("\nThree Address Code:\n");
    parse();
    return 0;
}
void parse()
{
    E();
}
void genTAC(char *op, char *arg1, char *arg2)
{
    char tempVar[10];
    sprintf(tempVar, "t%d", tempCount++); 
    if (arg2 != NULL)
	{
        printf("%s = %s %s %s\n", tempVar, arg1, op, arg2);
    }
	else
	{
        printf("%s = %s\n", tempVar, arg1);
    }
}
void E()
{ 
    T(); 
    while (input[index] == '+' || input[index] == '-')
	{
        char op[2];
        op[0] = input[index++];
        op[1] = '\0';
        T(); 
        char arg1[10], arg2[10];
        sprintf(arg1, "t%d", tempCount - 2); 
        sprintf(arg2, "t%d", tempCount - 1); 
        genTAC(op, arg1, arg2); 
    }
}
void T()
{ 
    F(); 
    while (input[index] == '*' || input[index] == '/')
	{
        char op[2];
        op[0] = input[index++];
        op[1] = '\0';
        F(); 
        char arg1[10], arg2[10];
        sprintf(arg1, "t%d", tempCount - 2); 
        sprintf(arg2, "t%d", tempCount - 1);
        genTAC(op, arg1, arg2); 
    }
}
void F()
{
    if (input[index] == '(')
	{
        index++; 
        E(); 
        if (input[index] == ')')
		{
            index++; 
        }
		else
		{
            printf("Error: Missing closing parenthesis.\n");
            exit(1);
        }
    }
	else if (isalnum(input[index]))
	{ 
        char arg[10];
        sscanf(&input[index], "%s", arg); 
        index += strlen(arg); 
        genTAC("", arg, NULL); 
    }
	else
	{
        printf("Error: Invalid character '%c'.\n", input[index]);
        exit(1);
    }
}
