#include <stdio.h>
#include <stdlib.h>
#include "arcade.h"

// Copyright [2025] <Andrei Riciu>

int main() {
    int task_num, N, M, **mat;
    scanf("%d%d%d", &task_num, &N, &M);
    mat = malloc(N * sizeof(int*));
    if (mat) {
        for (int i = 0; i < N; i++) {
            mat[i] = malloc(M * sizeof(int));
            if (mat[i]) {
                for (int j = 0; j < M; j++)
                    scanf("%d", *(mat + i) + j);
            } else {
                for (int k = 0; k <= i; k++)
                    free(mat[k]);
                free(mat);
            }
        }
    } else {
        free(mat);
        return -1;
    }
    switch (task_num) {
    case 1:
        // task1
        {
            int col, num_poz;
            scanf("%d%d", &col, &num_poz);
            perm(mat, N, col, num_poz);
            for (int i = 0; i < N; i++, printf("\n"))
                for (int j = 0; j < M; j++)
                    printf("%d ", mat[i][j]);
            break;
        }
    case 2: {
        // task2
        int *combinatii, *scor;
        combinatii = calloc(1, sizeof(int));
        scor = calloc(1, sizeof(int));
        calcul_lin(mat, M, combinatii, scor);
        calcul_diag(mat, M, combinatii, scor);

        if (count_dist(mat, M) <= 4)
            *scor += 15;
        if (count_dist(mat, M) <= 2)
            *scor += 85;
        printf("%d\n%d\n", *combinatii, *scor);
        free(combinatii);
        free(scor);
        break;
    }
    case 3: {
        // task3
        int *scor_total, T;
        scor_total = calloc(1, sizeof(int));
        scanf("%d", &T);
        for (int i = 1; i <= T; i++) {
            int col, num_poz;
            scanf("%d%d", &col, &num_poz);
            perm(mat, N, col, num_poz);
            *scor_total += total_score(mat, M);
        }

        printf("%d\n", *scor_total);
        free(scor_total);
    } break;
    case 4: {
        // task4
        int scor_max = 0, *comb;
        comb = calloc(1, sizeof(int));
        if (!comb)
            return -1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < M; j++) {
                int* scor;
                scor = calloc(1, sizeof(int));
                if (!scor)
                    return -1;
                if (j < M - 1 && mat[i][j] != mat[i][j + 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i][j + 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                if (j > 1 && mat[i][j] != mat[i][j - 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i][j - 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                if (j < M - 1 && i < 2 && mat[i][j] != mat[i + 1][j + 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i + 1][j + 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                if (i > 0 && j > 0 && mat[i][j] != mat[i - 1][j - 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i - 1][j - 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                if (i > 0 && j < M - 1 && mat[i][j] != mat[i - 1][j + 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i - 1][j + 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                if (i < 2 && j > 0 && mat[i][j] != mat[i + 1][j - 1]) {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i + 1][j - 1];
                    *scor = total_score(mat, M);
                    if (*scor > scor_max)
                        scor_max = *scor;
                    mat[i][j] = aux;
                }
                free(scor);
            }
        printf("%d\n", scor_max);
        free(comb);
    } break;
    case 5: {
        // task5
        int scor_max = 0;
        for (int i = 0; i < M - 1; i++)
            for (int j = i + 1; j < M; j++) {
                for (int c1 = 1; c1 <= N; c1++) {
                    for (int c2 = 1; c2 <= N; c2++) {
                        if (total_score(mat, M) > scor_max)
                            scor_max = total_score(mat, M);
                        perm(mat, N, j, 1);
                    }
                    perm(mat, N, i, 1);
                }
            }
        printf("%d\n", scor_max);
    } break;
    default:
        break;
    }
    for (int i = 0; i < N; i++)
        free(mat[i]);
    free(mat);
    return 0;
}
