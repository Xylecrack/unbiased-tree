#include <stdio.h>

int main(int argc,char *argv[]) {
    char *src = argv[1];
    char *dest=argv[2];

    FILE *srcFile = fopen(src, "r");

    FILE *destFile = fopen(dest, "w");

    char ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("File copied successfully\n");
    return 0;
}