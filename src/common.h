//
// Created by pysga on 15/03/2025.
//

#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <time.h>
#define TRUE 1
const int FALSE = 0;
using namespace std;
const int MAX = 2000000;

void LoadFile(int *&A, int &n);

double ThoiGian(clock_t start, clock_t end);

void TaoFileNgauNhien(int n);

void Lietke(int A[], long n);

void GhiChunkFile(int* A, long n, FILE* f);

#endif //COMMON_H
