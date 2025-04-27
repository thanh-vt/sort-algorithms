//
// Created by pysga on 15/03/2025.
//

#include "selection_sort.h"

void Selection_Sort(int A[], int n) {
    cout << "\nThoi gian chay cua Selection:";
    clock_t t1, t2;
    t1 = clock();
    int min, vitrimin;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        min = A[i];
        vitrimin = i;
        for (j = i + 1; j < n; j++)
            if (A[j] < min) {
                min = A[j];
                vitrimin = j;
                //delay(10);
            }
        // Doi cho 2 phan tu A[i] va A[vitrimin]

        A[vitrimin] = A[i];
        A[i] = min;
    }
    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}
