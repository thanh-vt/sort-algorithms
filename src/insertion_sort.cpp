//
// Created by pysga on 15/03/2025.
//

#include "insertion_sort.h"

void Insertion_Sort(int A[], int n) {
    cout << "\nThoi gian chay cua Insertion:";
    clock_t t1, t2;
    t1 = clock();
    int x;
    int i, j;
    for (i = 1; i < n; i++) {
        x = A[i];
        for (j = i - 1; j >= 0 && x < A[j]; j--) // tim vi tri sc x >=A[j]
            A[j + 1] = A[j];
        A[j + 1] = x;
    }
    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}
