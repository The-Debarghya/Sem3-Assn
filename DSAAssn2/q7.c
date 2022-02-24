/*
Take  an  arbitrary  Matrix  of positive  integers, say,  128 X 128. Also take
integer  matrices of size 3 X 3 and 5 X 5. Find out an output matrix of size
128 X 128 by multiplying the small matrix with the corresponding submatrix of
the large matrix with the centre of the small matrix placed  at  the  individual
positions  within  the  large  matrix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __dline__ "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
#define ull unsigned long long
#define dim 128
#define mod 10

void initMatrix(ull (*matrix)[dim]){
    srand(time(NULL));
    for (ull i = 0; i < dim; i++){
        for (ull j = 0; j < dim; j++){
            matrix[i][j] = rand() % mod;
        }
    }
}
void mulMatrix(ull (*matrix)[dim], ull x, ull y, ull *secMatrix, ull n){
    ull i, j, k, sum;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            sum = 0;
            for (k = 0; k < n; k++){
                sum += matrix[i + x - n / 2][k + y - n / 2] * (*(secMatrix + (k * n) + j));
            }
            matrix[i + x - n / 2][j + y - n / 2] = sum;
        }
    }
}
int main(int argc, char **argv){
    // system("cls");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ull i, j, n;
    ull matrix[dim][dim];
    initMatrix(matrix);
    printf("The original matrix:\n");
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf("%llu, ", matrix[i][j]);
        }
        printf("\n");
    }
    printf(__dline__);
    // printf("Enter the dimension of the second matrix = ");
    scanf(" %llu", &n);
    ull *secMatrix = (ull *)calloc(n * n, sizeof(int));
    // printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            scanf(" %llu", (secMatrix + i * n) + j);
    }
    // printf("\n");
    // printf(__dline__);
    for (i = n / 2; i < dim - n / 2; i++){
        for (j = n / 2; j < dim - n / 2; j++){
            mulMatrix(matrix, i, j, secMatrix, n);
        }
    }

    printf("The matrix after multiplication:\n");
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf("%llu, ", matrix[i][j]);
        }
        printf("\n");
    }
    printf(__dline__);
    fflush(stdin);
    fflush(stdout);
    free(secMatrix);
    return 0;
}
