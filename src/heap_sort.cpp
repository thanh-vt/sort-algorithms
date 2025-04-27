//
// Created by pysga on 15/03/2025.
//

#include "heap_sort.h"

void Adjust(int A[], int r, int n);

void Heap_sort(int A[], int n) {
    cout << "Thoi gian chay cua Heap Sort :";
    clock_t t1, t2;
    t1 = clock();
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--) // Tao heap ban dau
        Adjust(A, i, n);
    for (i = n - 2; i >= 0; i--) {
        temp = A[0]; // Cho A[0] ve cuoi heap
        A[0] = A[i + 1];
        A[i + 1] = temp;
        //Lietke(A,n);
        Adjust(A, 0, i + 1); // Dieu chinh lai heap tai vi tri 0
        // Luc nay, 2 cay con o vi tri 1 va 2 da la heap
    }
    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}

void Adjust(int A[], int r, int n) {
    int j = 2 * r + 1; // vi tri nut con ben trai
    int x = A[r];
    int cont = TRUE;
    while (j <= n - 1 && cont) {
        if (j < n - 1) // luc nay r moi co nut con ben phai. Neu j=n-1 thi r khong
            // co nut con ben phai
                if (A[j] < A[j + 1]) // tim vi tri nut con lon hon
                    j++;
        if (A[j] <= x)
            cont = FALSE;
        else {
            // di chuyen nut con j len r
            A[r] = A[j];
            r = j; // xem lai nut con co phai la dong khong
            j = 2 * r + 1;
        }
    }
    A[r] = x;
}
