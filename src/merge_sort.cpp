//
// Created by pysga on 15/03/2025.
//

#include "merge_sort.h"

void Merge_sort(int A[], int n) {
    int i, j, k, l, t;
    int h, m, q, r;
    int p = 1; // do dai cua day con duoc tron, sau moi buoc p duoc tang doi
    int up = TRUE; //chieu cua dong du lieu ;
    // up=TRUE cac thanh phan a0...a(n-1) duoc chuyen toi cac tanh phan a(n)..a(2n-1)
    // up=FALSE thi nguoc lai
    // Mien chi so la 0..2n-1
    do {
        h = 1;
        m = n; // m la so phan tu duoc tron
        if (up) {
            i = 0;
            j = n - 1;
            k = n;
            l = 2 * n - 1;
        } else {
            k = 0;
            l = n - 1;
            i = n;
            j = 2 * n - 1;
        }
        do // tron 1 duong chay (p) phan tu tu i va j vao k va l.
        // q la do dai duong chay i, r la do dai duong chay j
        {
            if (m >= p)
                q = p;
            else {
                q = m;
                m = m - q;
            }
            if (m >= p)
                r = p;
            else {
                r = m;
                m = m - r;
            }
            while (q != 0 && r != 0) {
                // tron
                if (A[i] < A[j]) {
                    A[k] = A[i];
                    k += h;
                    i++;
                    q--;
                } else {
                    A[k] = A[j];
                    k += h;
                    j--;
                    r--;
                }
            }
            // chep phan con lai cua duong chay j
            while (r > 0) {
                A[k] = A[j];
                k += h;
                j--;
                r--;
            }
            // chep phan con lai cua duong chay i
            while (q > 0) {
                A[k] = A[i];
                k += h;
                i++;
                q--;
            }
            h = -h;
            t = k;
            k = l;
            l = t; // Hoan doi (k,l)
        } while (m != 0);

        up = !up;
        p = 2 * p;
    } while (p < n);
    if (!up)
        for (i = 0; i < n; i++)
            A[i] = A[i + n];
}
