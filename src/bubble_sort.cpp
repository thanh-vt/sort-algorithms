//
// Created by pysga on 15/03/2025.
//

#include "bubble_sort.h"

void Bubble_Sort(int A[], int n) {
    int i, j, temp;
    cout << "\nThoi gian chay cua Bubble:";
    clock_t t1, t2;
    t1 = clock();

    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            if (A[j - 1] > A[j]) {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }

    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}