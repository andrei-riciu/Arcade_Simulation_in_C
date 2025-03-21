#include <stdio.h>
#include <stdlib.h>

// Copyright [2025] <Andrei Riciu>

void perm(int** mat, int N, int col, int nr_poz);

void calcul_lin(int** mat, int M, int* combinatii, int* scor);

void calcul_diag(int** mat, int M, int* combinatii, int* scor);

int count_dist(int** mat, int M);

int total_score(int** mat, int M);


