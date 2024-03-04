#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 10


int is_operator(char c) {
    char operators[] = "+-*/=";
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}


int is_keyword(const char *str) {
    const char *keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return", "main"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


void analyze(char *input) {
    int length = strlen(input);
    char current[MAX_IDENTIFIER_LENGTH];
    int current_length = 0;
    int in_comment = 0;

    for (int i = 0; i < length; i++) {
        // Check for comment start
        if (input[i] == '/' && i + 1 < length && input[i + 1] == '/') {
            in_comment = 1;
            continue;
        }
        
        if (in_comment && input[i] == '\n') {
            in_comment = 0;
            continue;
        }
       
        if (in_comment) {
            continue;
        }
      
        if (is_operator(input[i])) {
            printf("Operator: %c\n", input[i]);
            continue;
        }
      
        if (isalpha(input[i])) {
            
            while (isalnum(input[i])) {
                
                current[current_length++] = input[i];
                i++;
            }
            current[current_length] = '\0';
            if (is_keyword(current)) {
                printf("Keyword: %s\n", current);
            } else {
                printf("Identifier: %s\n", current);
            }
            current_length = 0;
            continue;
        }
     
        if (isdigit(input[i])) {
            
            while (isdigit(input[i]) || input[i] == '.') {
                
                current[current_length++] = input[i];
                i++;
            }
            current[current_length] = '\0';
            printf("Constant: %s\n", current);
            current_length = 0;
            continue;
        }
    }
}

int main() {
    char input[] = "int main() {\n //comment \n    int a = 10;\n    float b = 3.14;\n    char c = 'c';\n    if (a > b)\n        return 1;\n    else\n        return 0;\n}";
    analyze(input);
    return 0;
}

