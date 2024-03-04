#include <stdio.h>
#include <ctype.h>

int main() {
    char input[] = "This is a sample\ninput with\twhitespaces.";

    int whitespace_count = 0;
    int newline_count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            whitespace_count++;
            if (input[i] == '\n') {
                newline_count++;
            }
        }
    }

    printf("Number of whitespaces: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}

