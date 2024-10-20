#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getLength(char *line){

    int length = 0;

    for (int i = 0; line[i] != '\0'; i++){
        length += 1;
    }

    return length;
}

int main(int argc, char *argv[]){
    
    if (argc < 4 || argc > 4){
        printf("Too many or too little command line arguments.\n");
        exit(1);
    }
    
    FILE *readFile = fopen(argv[1], "r");
    FILE *shortFile = fopen(argv[2], "w");
    FILE *longFile = fopen(argv[3], "w");

    if (readFile == NULL || shortFile == NULL || longFile == NULL){
        exit(1);
    }

    char line[1000];
    int shortCount = 0;
    int longCount = 0;
    while(fgets(line, 1000, readFile) != NULL){

        int length = getLength(line);

        if (length < 20){
            for (int i = 0; i < length; i++){
                line[i] = toupper(line[i]);
            }
            fprintf(shortFile, "%s", line);
            shortCount += 1;
        }
        else{
            for (int i; i < length; i++){
                line[i] = tolower(line[i]);
            }
            fprintf(longFile, "%s", line);
            longCount += 1;
        }
    }

    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);


    fclose(readFile);
    fclose(shortFile);
    fclose(longFile);
}