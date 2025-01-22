#include <stdio.h>
int main(int argc, char *argv[])
{
    char *src1 = argv[1];
    char *src2 = argv[2];
    char *dest = argv[3];
    FILE *srcFile1 = fopen(src1, "r");
    FILE *srcFile2 = fopen(src2, "r");
    FILE *destFile = fopen(dest, "w");
    char line[1024];
    while (fgets(line, sizeof(line), srcFile1))
    {
        fputs(line, destFile);
    }
    while (fgets(line, sizeof(line), srcFile2))
    {
        fputs(line, destFile);
    }
    fclose(srcFile1);
    fclose(srcFile2);
    fclose(destFile);
    printf("Files concatenated successfully\n");
    return 0;
}