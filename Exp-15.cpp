#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void countCharactersWordsLines(FILE *file, int *charCount, int *wordCount, int *lineCount);
int main() 
{
    FILE *file;
    char filename[100];
    int charCount = 0, wordCount = 0, lineCount = 0;
    printf("Enter the filename to analyze: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
	{
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    countCharactersWordsLines(file, &charCount, &wordCount, &lineCount);
    fclose(file);

    printf("\nResults:\n");
    printf("Total characters: %d\n", charCount);
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);

    return EXIT_SUCCESS;
}
void countCharactersWordsLines(FILE *file, int *charCount, int *wordCount, int *lineCount) {
    char ch;
    int inWord = 0;
    while ((ch = fgetc(file)) != EOF)
	{
        (*charCount)++; 
        if (ch == '\n')
		{
            (*lineCount)++; 
        }
        if (isspace(ch))
		{
            inWord = 0; 
        }
		else if (!inWord)
		{
            inWord = 1; 
            (*wordCount)++; 
        }
    }
}
