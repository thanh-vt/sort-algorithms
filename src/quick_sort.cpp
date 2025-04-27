//
// Created by pysga on 15/03/2025.
//

#include "quick_sort.h"

void Quick_Sort(int A[], int n) {
    struct Element_Stack // ki?u ph?n t? trong Stack
    {
        int q, r;
    };
    clock_t t1, t2;
    t1 = clock();
    cout << "Thoi gian chay cua Quick Sort khong de qui:";
    Element_Stack Stack[50]; // Stack c� t?i ?a 50 ph?n t?
    int sp = 0; // con tr? Stack, kh?i t?o sp=0
    int i, j, x, q, r, temp;
    Stack[0].q = 0; // ch? s? ??u c?a m?ng c?n s?p
    Stack[0].r = n - 1; // ch? s? cu?i c?a m?ng c?n s?p
    do {
        // L?y m?t ph�n ho?ch ra t? Stack
        q = Stack[sp].q;
        r = Stack[sp].r;
        sp--; // X�a 1 ph?n t? kh?i Stack
        do {
            // Ph�n ?o?n d�y con a[q],..., a[r]
            x = A[(q + r) / 2]; // L?y ph?n t? gi?a c?a d�y c?n s?p th? t? l�m ch?t
            i = q;
            j = r;
            do {
                while (A[i] < x) i++; //T�m ph?n t? ??u ti�n c� tr? l?n h?n hay b?ng x
                while (A[j] > x) j--; //T�m ph?n t? ??u ti�n c� tr? nh? h?n hay b?ng x
                if (i <= j) // ??i ch? A[i] v?i A[j]
                {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    i++;
                    j--;
                }
            } while (i <= j);
            if (i < r) // ph?n th? ba c� t? 2 ph?n t? tr? l�n
            {
                // ??a v�o Stack ch? s? ??u v� ch? s? cu?i c?a ph?n th? ba
                sp++;
                Stack[sp].q = i;
                Stack[sp].r = r;
            }
            r = j; // Chu?n b? v? tr� ?? ph�n ho?ch ph?n c� gi� tr? nh? h?n ch?t
        } while (q < r);
    } while (sp != -1); // Ket thuc khi Stack rong
    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}

void Quick_Sort_Dequi(int A[], int n) {
    clock_t t1, t2;
    cout << "\nThoi gian chay cua Quick Sort:";
    t1 = clock();

    Sort(A, 0, n - 1); // G�i h�m Sort v�i ph�n t� (r)�u c� ch� s� 0 (r)�n 	// ph�n t� cu�i c�ng c� ch� s� n-1
    t2 = clock();
    cout << ThoiGian(t1, t2) << "giay \n";
}

void Sort(int A[], long q, long r) {
    int temp;
    int i = q;
    int j = r;
    int x = A[(q + r) / 2]; //L�y ph�n t� gi�a c�a d*y c�n s3/4p th� t� l�m ch�t
    do {
        // Ph(c)n (r)o�n d�y con a[q],..., a[r]
        while (A[i] < x) i++; //T�m ph�n t� (r)�u ti�n c� tr� l�n h�n hay b"ng x
        while (A[j] > x) j--; //T�m ph�n t� (r)�u ti�n c� tr� nh� h�n hay b"ng x
        if (i <= j) // Doi cho A[i] voi A[j]
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (q < j) // ph�n th� nh�t c� t� 2 ph�n t� tr� l�n
        Sort(A, q, j);
    if (i < r) // ph�n th� ba c� t� 2 ph�n t� tr� l�n
        Sort(A, i, r);
}
