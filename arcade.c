#include "arcade.h"

// Copyright [2025] <Andrei Riciu>

void perm(int** mat, int N, int col, int nr_poz) {
    for (int k = 1; k <= nr_poz; k++) {
        int aux = mat[N - 1][col];
        for (int i = N - 1; i >= 1; i--)
            mat[i][col] = mat[i - 1][col];
        mat[0][col] = aux;
    }
}
void calcul_lin(int** mat, int M, int* combinatii, int* scor) {
    int comb_num = 0, score = 0;
    for (int i = 0; i < 3; i++) {
        int elem = mat[i][0], nr_elem = 1, nr_elem_max = 1,
            elem_max = mat[i][0];
        for (int j = 1; j < M; j++) {
            if (elem != mat[i][j]) {
                if (nr_elem > nr_elem_max) {
                    nr_elem_max = nr_elem;
                    elem_max = elem;
                }
                elem = mat[i][j];
                nr_elem = 1;
            } else {
                nr_elem++;
            }
        }
        if (nr_elem > nr_elem_max) {
            nr_elem_max = nr_elem;
            elem_max = elem;
        }
        if (nr_elem_max >= 3) {
            comb_num++;
            if (elem_max == 7)
                nr_elem_max *= 2;
            score += nr_elem_max;
        }
    }
    *combinatii += comb_num;
    *scor += score;
}
void calcul_diag(int** mat, int M, int* combinatii, int* scor) {
    int score = 0, comb_num = 0;
    for (int j = 0; j < M; j++) {
        if (j < M - 2) {
            if (mat[0][j] == mat[1][j + 1] && mat[1][j + 1] == mat[2][j + 2]) {
                comb_num++;
                if (mat[0][j] == 7)
                    score += 14;
                else
                    score += 7;
            }
        }
        if (j >= 2) {
            if (mat[0][j] == mat[1][j - 1] && mat[1][j - 1] == mat[2][j - 2]) {
                if (mat[0][j - 2] == mat[2][j]
                    && mat[0][j - 2] == mat[1][j - 1]) {
                    if (mat[0][j] == 7)
                        score += 28;
                    else
                        score += 14;
                } else {
                    comb_num++;
                    if (mat[0][j] == 7)
                        score += 14;
                    else
                        score += 7;
                }
            }
        }
    }
    *combinatii += comb_num;
    *scor += score;
}
int count_dist(int** mat, int M) {
    int count = 0, *fr;
    fr = calloc(10, sizeof(int));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < M; j++)
            fr[mat[i][j]]++;
    for (int i = 0; i <= 9; i++)
        if (fr[i])
            count++;
    free(fr);
    return count;
}
int total_score(int** mat, int M) {
    int *score = calloc(1, sizeof(int)), *comb = calloc(1, sizeof(int));
    if (!score || !comb)
        return -1;
    calcul_diag(mat, M, comb, score);
    calcul_lin(mat, M, comb, score);
    if (count_dist(mat, M) <= 4)
        *score += 15;
    if (count_dist(mat, M) <= 2)
        *score += 85;
    int scor = *score;
    free(score);
    free(comb);
    return scor;
}