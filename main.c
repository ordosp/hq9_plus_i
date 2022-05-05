#include <stdio.h>
#include <stdlib.h>


#define FILE_MAX_SIZE 4096


void run(char *program) {
    FILE *f;
    char buf;
    int i = 0;
    char fileContent[FILE_MAX_SIZE];
    int currentCommand = 0;
    int counter = 0;

    f = fopen(program, "r");
    while(!feof(f)) {
        fscanf(f, "%c", &buf);
        fileContent[i] = buf;
        i++;
    }
    fclose(f);
    fileContent[i] = '\0';
    while (1) {
        switch (fileContent[currentCommand]) {
            case 'H':
                printf("Hello world!\n");
                break;
            case 'Q':
                i = 0;
                while (fileContent[i] != '\0') {
                    if (fileContent[i] != '\n') printf("%c", fileContent[i]); i++;
                }
                printf("\n");
                break;
            case '9':
                for (int b=99; b>0; b--) {
                    printf("%d %s of beer on the wall\n", b, b == 1 ? "bottle" : "bottles");
                    printf("%d %s of beer!\n", b, b == 1 ? "bottle" : "bottles");
                    printf("Take one down, pass it around\n");
                    if (b - 1 == 0) {
                        printf("No more %s of beer on the wall!\n\n", b == 1 ? "bottle" : "bottles");
                    } else {
                        printf("%d %s of beer on the wall!\n\n", b - 1, b == 1 ? "bottle" : "bottles");
                    }
                }
                printf("No more bottles of beer on the wall, no more bottles of beer.\n");
                printf("Go to the store and buy some more, 99 bottles of beer on the wall.\n");
                break;
            case '+':
                counter++;
                break;
        }
        currentCommand++;
        if (fileContent[currentCommand] == '\0') {
            break;
        }
    }
}


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("hq9_plus_i <source-file>\n");
        exit(1);
    }

    run(argv[1]);
    return 0;
}
