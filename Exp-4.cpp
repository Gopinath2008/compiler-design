#include<stdio.h>
#include<string.h>
int main()
{
    const char *input = "int main() {\n"
                        "    int x = 10 + 20 - 5 * 2 / 1;\n"
                        "    x = x + 1;\n"
                        "    printf(\"x = %d\\n\", x);  // Print x\n"
                        "}\n";
    int i=0;
    while (input[i] != '\0') 
	{
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') 
		{
            printf("Operator: %c\n", input[i]);
        }
        i++;
    }
}
