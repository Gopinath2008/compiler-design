#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    const char *input = "int main() {\n"
                        "    int x = 10 + 20 - 5 * 2 / 1;\n"
                        "    x = x + 1;\n"
                        "    printf(\"x = %d\\n\", x);  // Print x\n"
                        "}\n";

    int whitespace_count = 0;
    int newline_count = 0;
    int i = 0;
    while (input[i] != '\0')
	{
        if (input[i] == ' ' || input[i] == '\t')
		{
            whitespace_count++;
        }
		else if (input[i] == '\n')
		{
            newline_count++;
        }
        i++;
    }
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);
}
