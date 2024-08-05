#include <stdio.h>
#include <string.h>
int main()
{
    const char *test_lines[] =
	{
        "// This is a single-line comment",
        "/* This is a multi-line comment */",
        "int x = 0; // This is code with a comment",
        "This is not a comment",
        "/* This is a\nmulti-line comment */",
        "Some code /* with a comment */ in the middle"
    };
    int num_lines = sizeof(test_lines) / sizeof(test_lines[0]);
    for(int i = 0; i < num_lines; i++)
	{
        const char *line = test_lines[i];
        while (*line == ' ' || *line == '\t')
		{
            line++;
        }
        if (strncmp(line, "//", 2) == 0)
		{
            printf("Line: %s\nIs Comment: True\n\n", test_lines[i]);
            continue;
        }
        if (strncmp(line, "/*", 2) == 0 && strstr(line, "*/") != NULL)
		{
            printf("Line: %s\nIs Comment: True\n\n", test_lines[i]);
            continue;
        }
        printf("Line: %s\nIs Comment: False\n\n", test_lines[i]);
    }
    return 0;
}
