#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100]; // To store the input string
int i = 0;       // Current index in the input string

// Function prototypes
int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("\nTop-Down Parsing for the following grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | e\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | e\n");
    printf("F  -> ( E ) | ID\n");
    
    printf("\nEnter the string to be checked: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    if (E()) {
        if (input[i] == '\0') {
            printf("\nString is accepted\n");
        } else {
            printf("\nString is not accepted\n");
        }
    } else {
        printf("\nString is not accepted\n");
    }

    return 0; 
} 

int E() { 
    if (T()) { 
        return EP();
    }
    return 0;
} 

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            return EP();
        }
        return 0;
    }
    return 1; // E' can be e
} 

int T() { 
    if (F()) { 
        return TP();
    }
    return 0;
} 

int TP() {
    if (input[i] == '*') { 
        i++;
        if (F()) {
            return TP();
        }
        return 0;
    }
    return 1; // T' can be e
} 

int F() {
    if (input[i] == '(') {
        i++; 
        if (E()) {
            if (input[i] == ')') { 
                i++;
                return 1;
            }
            return 0; // Missing closing parenthesis
        }
        return 0; // Invalid expression
    } else if (isalnum(input[i])) { // Check if it's an ID
        i++;
        return 1; // ID recognized
    }
    return 0; // Invalid token
}

