#include <stdio.h>
#include <stdlib.h>

void printArray(int* tab, int size) {
    printf("[ ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
    return;
}

int fillArray(int* tab, int size) {
    if (tab == NULL) {
        printf("Error: tab is NULL.\n");
        return 1;
    }

    int i;
    for (i = 1; i <= size; i++) {
        tab[i - 1] = i;
    }

    return 0;;
}

int* allocIntArray(int size) {
    return malloc(size * sizeof(int));
}

void freeArray(int* tab) {
    free(tab);
    return;
}

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    if (size < 1) {
        printf("Error: size must be greater than 0.\n");
        return 1;
    }

    
    int* tab = allocIntArray(size);

    fillArray(tab, size);
    printArray(tab, size);

    freeArray(tab);
    return 0;
}