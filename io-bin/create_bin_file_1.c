#include <stdio.h>

int main() {
    FILE *fp = fopen("file1.bin", "wb");
    if (!fp) {
        perror("An error occurred opening the file");
        return 1;
    }

    int i = 100;
    float f = 20.5;

    fwrite(&i, sizeof(int), 1, fp);
    fwrite(&f, sizeof(float), 1, fp);

    fclose(fp);

    return 0;
}

