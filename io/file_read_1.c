#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int main() {
    FILE *fd = fopen("file.txt", "r");
    if (fd == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX];
    while (fgets(buffer, MAX, fd) != NULL) {
        printf("%s", buffer);
    }

    fclose(fd);

    return EXIT_SUCCESS;
}
