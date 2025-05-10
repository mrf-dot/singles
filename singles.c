#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char str[2] = {'\0', '\0'};
    FILE *fptr = NULL;
    mkdir("filenames", 0755);
    chdir("filenames");
    for (unsigned char c = 1; c < 128; c++) {
        // filenames with slashes and dots are illegal
        if (c == '/' || c == '.') {
            continue;
        }
        printf("Creating file: %c (%d ASCII value)\n", c, c);
        str[0] = c;
        fptr = fopen(str, "w+");
        fclose(fptr);
    }
    return 0;
}

