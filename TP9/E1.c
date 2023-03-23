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

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    if (size < 1) {
        printf("Error: size must be greater than 0.\n");
        return 1;
    }

    int* tab = malloc(size * sizeof(int));

    int i;
    for (i = 1; i <= size; i++) {
        tab[i - 1] = i;
    }

    printArray(tab, size);
    
    free(tab);
    return 0;
}