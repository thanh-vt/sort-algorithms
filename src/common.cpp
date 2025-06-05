//
// Created by pysga on 15/03/2025.
//
#include "common.h"

void LoadFile(int *&A, int &n) {
    FILE *f;
    f = fopen("day2trieuso.txt", "rt");
    fscanf(f, "%d ", &n);
    if (A == NULL)
        A = new int [n];
    for (int i = 0; i < n; i++)
        fscanf(f, "%d ", &A[i]);
    fclose(f);
}


double ThoiGian(clock_t start, clock_t end) {
    return double(end - start) / CLOCKS_PER_SEC;
}

void TaoFileNgauNhien(int n) {
    FILE *f;
    f = fopen("day2TRIEUso.txt", "wt");
    srand(time(NULL));
    int i = 1;
    fprintf(f, "%d\n ", n);
    while (i <= n) {
        fprintf(f, "%10d ", (rand() % n) + 1); //tra ve so ngau nhien tu 1 -> 30000
        if (i % 10 == 0) fprintf(f, "\n");
        i++;
    }
    fclose(f);
}

void Lietke(int *A, long n) {
    for (long i = 0; i < n; i++) {
        int x = A[i];
        printf("%8d ", x);
        if (i + 1 % 10 == 0) cout << endl;
    }
}

void write_sorted_chunks_to_file(int *A, long n, FILE *f) {
    for (long i = 0; i < n; i++) {
        fprintf(f, "%8d ", A[i]);
    }
    fprintf(f, "\n");
}
