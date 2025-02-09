// matrix-multiplication <Project2.cpp>
// ECE 312 Project 2 submission by
// Alice Di Mauro
// ad55559
// Slip days used: <0>
// Spring 2025

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
        
        for (uint32_t i = 0; i < a_rows; i++) { // Iterates over rows of matrix A.
            for (uint32_t j = 0; j < b_cols; j++) { // Iterates over columns of Matrix B
                c[i * b_cols + j] = 0.0; // Initialized to zero
                for (uint32_t k = 0; k < a_cols; k++) { // Iterates over columns of A | rows of B
                    c[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j]; // Multiplies elements + accumulates result
            }
        }
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
            double** c = (double**)malloc(a_rows * sizeof(double*)); // Dynamically allocates array of pointers 
            for (uint32_t i = 0; i < a_rows; i++) {
                c[i] = (double*)malloc(b_cols * sizeof(double)); // Allocates memory for each row in Matrix C
                for (uint32_t j = 0; j < b_cols; j++) {
                    c[i][j] = 0.0; // Initialization to zero 
                    for (uint32_t k = 0; k < a_cols; k++) {
                        c[i][j] += a[i][k] * b[k][j]; // Element multiplication + addition
                    }
                }
            }
            return c; // Returns newly allocated memory
}

// https://en.wikipedia.org/wiki/Matrix_(mathematics)#Submatrix

double** createSubMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols,
		 const uint32_t row_x, 
		 const uint32_t col_y) {
            double** subMatrix = (double**)malloc((a_rows - 1) * sizeof(double*)); // Allocates memory for row pointers with one row removed
            for (uint32_t i = 0, sub_i = 0; i < a_rows; i++) { // Loops over rows of original Matrix A
                if (i == row_x) continue; // Skips the row being removed
                subMatrix[sub_i] = (double*)malloc((a_cols - 1) * sizeof(double)); // Allocates memory for each row
                for (uint32_t j = 0, sub_j = 0; j < a_cols; j++) {
                    if (j == col_y) continue; // Skips column being removed
                    subMatrix[sub_i][sub_j] = a[i][j]; // Allocates memory for each column
                    sub_j++;
                }
                sub_i++;
            }
            return subMatrix; // Returns the dynamically allocated submatrix
}
