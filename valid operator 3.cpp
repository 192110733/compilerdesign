#include <stdio.h>


int validate_operator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/') {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    char operators[] = {'+', '-', '*', '/', '%', '='}; 
    int num_operators = sizeof(operators) / sizeof(operators[0]);

    printf("Valid Operators:\n");
    for (int i = 0; i < num_operators; i++) {
        if (validate_operator(operators[i])) {
            printf("%c\n", operators[i]);
        }
    }

    return 0;
}

