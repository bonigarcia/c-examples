#include <stdio.h>
#include <string.h>

#define SEPARATOR "/"

int main() {
    char str[80] = "50/70";
    char *token = strtok(str, SEPARATOR);

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, SEPARATOR);
    }

    printf("Original string: %s\n", str);
    return 0;
}
