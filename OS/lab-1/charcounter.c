#include <stdio.h>

int main(int argc, char *argv[])
{
    char *src = argv[1];
    FILE *srcfile = fopen(src, "r");
    int lines = 0;
    int words = 1;
    int chars = 0;
    char line[1024];
    while (fgets(line, sizeof(line), srcfile))
    {
        lines++;
        int i = 0;
        while (line[i] != '\0')
        {
            chars++;
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
            {
                words++;
            }
            i++;
        }
    }
    fclose(srcfile);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}