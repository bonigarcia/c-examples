#include <stdio.h>

int main() {
    FILE *fd = fopen("file1.bin", "wb");
    if (!fd) {
        perror("An error occurred opening the file");
        return 1;
    }

    int i = 100;
    float f = 20.5;

    fwrite(&i, sizeof(int), 1, fd);
    fwrite(&f, sizeof(float), 1, fd);

    fclose(fd);

    return 0;
}
