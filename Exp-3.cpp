#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKEN_LENGTH 100
void remove_whitespace_and_comments(const char *input, char *output)
{
    int i = 0, j = 0;
    int in_single_line_comment = 0;
    int in_multi_line_comment = 0;
    while (input[i] != '\0')
	{
        if (input[i] == '/' && input[i + 1] == '/')
		{
            in_single_line_comment = 1;
        }
        if (input[i] == '/' && input[i + 1] == '*')
		{
            in_multi_line_comment = 1;
        }
        if (in_single_line_comment && input[i] == '\n')
		{
            in_single_line_comment = 0;
            i++;
            continue;
        }
        if (in_multi_line_comment && input[i] == '*' && input[i + 1] == '/') 
		{
            in_multi_line_comment = 0;
            i += 2;
            continue;
        }
        if (in_single_line_comment || in_multi_line_comment)
		{
            i++;
            continue;
        }
        if (isspace(input[i]))
		{
            if (j == 0 || !isspace(output[j - 1]))
			{
                output[j++] = ' ';
            }
            i++;
            continue;
        }
        output[j++] = input[i++];
    }
    output[j] = '\0';
}
void tokenize(const char *input)
{
    char token[MAX_TOKEN_LENGTH];
    int i = 0, j = 0;
    while (input[i] != '\0')
	{
        if (isspace(input[i]))
		{
            i++;
            continue;
        }
        while (input[i] != '\0' && !isspace(input[i]))
		{
            token[j++] = input[i++];
        }
        token[j] = '\0';
        printf("Token: %s\n", token);
        j = 0;
    }
}
int main()
{
    const char *input = "int main() {\n"
                        "    // This is a single-line comment\n"
                        "    int x = 0; /* This is a\n"
                        "                  multi-line comment */\n"
                        "    x = x + 1;\n"
                        "    printf(\"x = %d\\n\", x);  // Print x\n"
                        "}\n";

    char processed_input[strlen(input) + 1];
    remove_whitespace_and_comments(input, processed_input);
    printf("Processed Input: %s\n", processed_input);
    tokenize(processed_input);
    return 0;
}
