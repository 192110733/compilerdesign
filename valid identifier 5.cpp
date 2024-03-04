#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidIdentifier(const char *identifier) {
   
    if (strlen(identifier) == 0) {
        return false;
    }

    if (!(isalpha(identifier[0]) || identifier[0] == '_')) {
        return false;
    }
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!(isalpha(identifier[i]) || isdigit(identifier[i]) || identifier[i] == '_')) {
            return false;
        }
    }

    return true;
}

int main() {
    char identifier1[] = "valid_identifier";
    char identifier2[] = "_123identifier";
    char identifier3[] = "invalid identifier";

    printf("%s is %svalid.\n", identifier1, isValidIdentifier(identifier1) ? "" : "in");
    printf("%s is %svalid.\n", identifier2, isValidIdentifier(identifier2) ? "" : "in");
    printf("%s is %svalid.\n", identifier3, isValidIdentifier(identifier3) ? "" : "in");

    return 0;
}

