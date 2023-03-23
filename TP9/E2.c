#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int dim1, dim2;
    printf("Donnez deux dimensions entières : ");
    scanf("%d %d", &dim1, &dim2);

    if (dim1 < 1 || dim2 < 1) {
        printf("Error: dimensions must be greater than 0.\n");
        return 1;
    }

    int** tab = (int**)malloc(dim1 * sizeof(int*));

    int i;
    for (i = 0; i < dim1; i++) {
        tab[i] = (int*)malloc(dim2 * sizeof(int));
    }

    int j;
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            tab[i][j] = 'a' + (i + j) % 26;
        }
    }

    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < dim1; i++) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}