/* Nhap vao n so nguyen ngau nhien va sort theo cac giai thuat  Sort*
   Tinh thoi gian thuc thi chuong trinh
*/
#include "bubble_sort.h"
#include "common.h"
#include "quick_sort.h"

#include <iostream>
#include <sstream>

void print_chunk(int *A, long n);

void merge_chunk_files(FILE *fin1, FILE *fin2, FILE *fout1, FILE *fout2, int source_chunk_size);

int main() {

    int n;
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
    while (fscanf(f, "%d ", &x) != EOF) {
        if (i >= chunk_size) {
            print_chunk(A, chunk_size);
            Quick_Sort_Dequi(A, chunk_size);
            if (chunk_counter % 2 == 0) {
                write_sorted_chunks_to_file(A, chunk_size, ta1);
            } else {
                write_sorted_chunks_to_file(A, chunk_size, ta2);
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
        print_chunk(A, chunk_size);
        Quick_Sort_Dequi(A, chunk_size);
        if (chunk_counter % 2 == 0) {
            write_sorted_chunks_to_file(A, chunk_size, ta1);
        } else {
            write_sorted_chunks_to_file(A, chunk_size, ta2);
        }
    }
    delete[] A;
    fclose(f);
    fclose(ta1);
    fclose(ta2);
    FILE *fin1, *fin2, *fout1, *fout2;
    int counter = 0;
    while (chunk_size < n) {
        if (counter % 2 == 0) {
            fin1 = fopen("ta1.txt", "rt");
            fin2 = fopen("ta2.txt", "rt");
            fout1 = fopen("tb1.txt", "wt");
            fout2 = fopen("tb2.txt", "wt");
        } else {
            fin1 = fopen("tb1.txt", "rt");
            fin2 = fopen("tb2.txt", "rt");
            fout1 = fopen("ta1.txt", "wt");
            fout2 = fopen("ta2.txt", "wt");
        }
        merge_chunk_files(fin1, fin2, fout1, fout2, chunk_size);
        fclose(fin1);
        fclose(fin2);
        fclose(fout1);
        fclose(fout2);
        chunk_size *= 2;
        counter++;
    }

    // FILE *fin1, *fin2, *fout1, *fout2;
    // string fout1_name = "ta1.txt";
    // string fout2_name = "ta2.txt";
    // int counter = 0;
    // char ch = 'b';
    // while (chunk_size < n) {
    //     fin1 = fopen(fout1_name.c_str(), "rt");
    //     fin2 = fopen(fout2_name.c_str(), "rt");
    //     string base_name = "t";
    //     string fname{ch++};
    //     fout1_name = base_name + fname + "1.txt";
    //     fout2_name = base_name + fname + "2.txt";
    //     fout1 = fopen(fout1_name.c_str(), "wt");
    //     fout2 = fopen(fout2_name.c_str(), "wt");
    //     merge_chunk_files(fin1, fin2, fout1, fout2, chunk_size);
    //     fclose(fin1);
    //     fclose(fin2);
    //     fclose(fout1);
    //     fclose(fout2);
    //     chunk_size *= 2;
    //     counter++;
    // }


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


void merge_chunk_files(FILE *fin1, FILE *fin2, FILE *fout1, FILE *fout2, int source_chunk_size) {
    FILE *fout;
    int chunk_idx = 0;
    int x1, x2;
    int fin1_has_more = fscanf(fin1, "%d ", &x1);
    int fin2_has_more = fscanf(fin2, "%d ", &x2);
    if (fin1_has_more <= 0 || fin2_has_more <= 0) {
        cout << "At least one of the 2 source file is empty" << endl;
        return;
    }
    do {
        if (chunk_idx % 2 == 0) {
            fout = fout1;
        } else {
            fout = fout2;
        }
        int i = 0, j = 0;
        while (i < source_chunk_size && j < source_chunk_size) {
            if (fin1_has_more > 0 && fin2_has_more <= 0) {
                fprintf(fout, "%8d ", x1);
                fin1_has_more = fscanf(fin1, "%d ", &x1);
                i++;
                continue;
            }
            if (fin1_has_more <= 0 && fin2_has_more > 0) {
                fprintf(fout, "%8d ", x2);
                fin2_has_more = fscanf(fin2, "%d ", &x2);
                j++;
                continue;
            }
            if (fin1_has_more <= 0) {
                break;
            }
            if (x1 < x2) {
                fprintf(fout, "%8d ", x1);
                fin1_has_more = fscanf(fin1, "%d ", &x1);
                i++;
            } else {
                fprintf(fout, "%8d ", x2);
                fin2_has_more = fscanf(fin2, "%d ", &x2);
                j++;
            }
        }
        while (i < source_chunk_size && fin1_has_more > 0) {
            fprintf(fout, "%8d ", x1);
            fin1_has_more = fscanf(fin1, "%d ", &x1);
            i++;
        }
        while (j < source_chunk_size && fin2_has_more > 0) {
            fprintf(fout, "%8d ", x2);
            fin2_has_more = fscanf(fin2, "%d ", &x2);
            j++;
        }
        chunk_idx++;
        fprintf(fout, "\n");
    } while (fin1_has_more > 0 || fin2_has_more > 0);
}


void print_chunk(int *A, long n) {
    for (long i = 0; i < n; i++) {
        int x = A[i];
        printf("%8d", x);
        if (i + 1 % n == 0) cout << endl;
    }
}
