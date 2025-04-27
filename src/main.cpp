/* Nhap vao n so nguyen ngau nhien va sort theo cac giai thuat  Sort*
   Tinh thoi gian thuc thi chuong trinh
*/
#include "bubble_sort.h"
#include "common.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include <iostream>
#include <string>
#include <sstream>

int merge_chunk(FILE* f1, FILE* f2, int chunk_idx) {

}

int main() {
    int n = MAX;
    // int *A;
    // A = NULL;
    // int A[MAX];
    //
    // TaoFileNgauNhien(n);
    int chunk_size = 10;
    // int *A = new int[chunk_size], *B = new int[chunk_size], *C = new int[chunk_size], *D = new int[chunk_size];
    FILE *f = fopen("day2trieuso.txt", "rt");
    fscanf(f, "%d ", &n);

    int x;
    int i = 0;
    int *A = new int[chunk_size];
    FILE *ta1 = fopen("ta1.txt", "wt");
    FILE *ta2 = fopen("ta2.txt", "wt");
    int chunk_counter = 0;
    while (fscanf(f, "%d", &x) != EOF) {
        if (i >= chunk_size) {
            Lietke(A, chunk_size);
            Quick_Sort_Dequi(A, chunk_size);
            if (chunk_counter % 2 == 0) {
                GhiChunkFile(A, chunk_size, ta1);
            } else {
                GhiChunkFile(A, chunk_size, ta2);
            }
            i = 0;
            delete[] A;
            A = new int[chunk_size];
            chunk_counter++;
        }
        A[i] = x;
        i++;
    }
    if (i > 0) {
        Lietke(A, chunk_size);
        Quick_Sort_Dequi(A, chunk_size);
        if (chunk_counter % 2 == 0) {
            GhiChunkFile(A, chunk_size, ta1);
        } else {
            GhiChunkFile(A, chunk_size, ta2);
        }
    }
    delete[] A;
    fclose(f);
    fclose(ta1);
    fclose(ta2);


    // Bubble_Sort( A,  n);  delete []A; A=NULL;
    // Selection_Sort( A,  n);  delete []A; A=NULL;
    // Quick_Sort_Dequi(A, n); delete []A; A=NULL;
    // Heap_sort (A,n);
    /*

     Bubble_Sort( A,  n);
     LoadFile(A,n);
    Insertion_Sort( A,  n);
     LoadFile(A,n);
     Selection_Sort( A,  n);
     LoadFile(A,n);
     Quick_Sort_Dequi (A,n);
   //  Heap_sort( A,  n);
     //cout << "\nDay sau khi sap\n";
     //Lietke(A,n);
     */

    return 0;
}
