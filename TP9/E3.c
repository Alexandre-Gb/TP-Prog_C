#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStringArray(char **tab, int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%s\n", tab[i]);
    }
}

void fillStringArray(char **tab, int size, char **argv){
    int i;
    for (i = 0; i < size; i++) {
        tab[i] = (char*)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        strcpy(tab[i], argv[i + 1]);
    }
}

char** allocStringArray(int size){
    return (char**)malloc(size * sizeof(char*));
}

void freeStringArray(char **tab, int size){
    int i;
    for (i = 0; i < size; i++) {
        free(tab[i]);
    }
    free(tab);
}

int main(int argc, char *argv[]){
    if (argc <= 1){
        printf("Error: no arguments.\n");
        return 1;
    }

    char** tab = allocStringArray(argc - 1);

    fillStringArray(tab, argc - 1, argv);
    printStringArray(tab, argc - 1);

    freeStringArray(tab, argc - 1);

    return 0;
}