#include <stdio.h>
#include <stdlib.h>

void print2dArray(int **tab, int dim1, int dim2){
    int i, j;
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int fill2dArray(int** tab, int dim1, int dim2) {
    if (tab == NULL) {
        printf("Error: tab is NULL.\n");
        return 1;
    }

    int i, j;
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            tab[i][j] = 'a' + (i + j) % 26;
        }
    }

    return 0;;
}

int** alloc2dIntArray(int dim1, int dim2) {
    int** tab = (int**)malloc(dim1 * sizeof(int*));

    int i;
    for (i = 0; i < dim1; i++) {
        tab[i] = (int*)malloc(dim2 * sizeof(int));
    }

    return tab;
}

void free2dArray(int **tab, int size){
    int i;
    for (i = 0; i < size; i++) {
        free(tab[i]);
    }
    free(tab);
}

int main(int argc, char* argv[]){
    int dim1, dim2;
    printf("Donnez deux dimensions entières : ");
    scanf("%d %d", &dim1, &dim2);

    if (dim1 < 1 || dim2 < 1) {
        printf("Error: dimensions must be greater than 0.\n");
        return 1;
    }

    int** tab = alloc2dIntArray(dim1, dim2);

    fill2dArray(tab, dim1, dim2);
    print2dArray(tab, dim1, dim2);

    free2dArray(tab, dim1);

    return 0;
}