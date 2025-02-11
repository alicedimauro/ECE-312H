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
        // Multiplies M X K to create Marix C
        double a[], // Don't need to use all these!! Delete if you want
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
        // https://en.wikipedia.org/wiki/Row-_and_column-major_order

        // NEED TO TEST FOR EDGE CASES LISTED ON ED
        if (a_cols <= 0 || a_rows <= 0 || b_cols <= 0) 
            return; // Exit function if we encounter a non-existing matrix
        
        for (uint32_t i = 0; i < a_rows; i++) { // Iterates over rows of matrix A (0 to M); first nested loop
            for (uint32_t j = 0; j < b_cols; j++) { // Iterates over columns of Matrix B (0 to K); second nested loop
                c[i * b_cols + j] = 0.0; // Initialized to zero formatted as a double
                for (uint32_t k = 0; k < a_cols; k++) { // Iterates over columns of A ("k-loop")
                    c[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j]; // Progressively expands Matrix C
                    // Accumulates result by multiplying results
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
        // https://en.wikipedia.org/wiki/Matrix_(mathematics)#Submatrix    
           
            
            if (a_rows <= 0 || a_cols <= 0 || b_cols <= 0 || a == NULL || b == NULL) 
                return NULL;
            // EDGE CASE LISTED ON ED: CHECKS MEMORY ALLOCATION

            double** c = (double**)malloc(a_rows * sizeof(double*)); // Dynamically allocates array of pointers
            if (c == NULL) // Ed discussion edge case
                return NULL; 
            for (uint32_t i = 0; i < a_rows; i++) {
                c[i] = (double*)malloc(b_cols * sizeof(double)); // Allocates memory for each row in Matrix C
                if (c[i] == NULL) 
                    return NULL; // EDGE CASE ASKED ABOUT ON ED
                for (uint32_t j = 0; j < b_cols; j++) {
                    c[i][j] = 0.0; // Initialization to zero in double format
                    for (uint32_t k = 0; k < a_cols; k++) {
                        c[i][j] += a[i][k] * b[k][j]; // Element multiplication + addition
                    }
                }
            }
            return c; // Returns new dynamic memory
            // Remember not to free!! Main does for you for this lab !!
            // You'd risk double freeing which could cause issues in Valgrind!
}



double** createSubMatrix( // Function needs to remove one row and one column from given matrix
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols,
		 const uint32_t row_x, 
		 const uint32_t col_y) {
            
            // MAKE SURE TO RETURN NULL IF WHEN MATRIX HAS NO ROWS 
            if (a_rows <= 1 || a_cols <= 1)
                return NULL;
            if (row_x >= a_rows || col_y >= a_cols)
                return a;

            double** subMatrix = (double**)malloc((a_rows - 1) * sizeof(double*)); // Allocates memory for row pointers with one row removed from given matrix
            if (subMatrix == NULL) 
                return NULL; // Memory allocation check
            for (uint32_t i = 0, sub_i = 0; i < a_rows; i++) { // Loops over all rows to build new matrix (original minus 1 row)
                // Can I initialize sub_i and i in the same for loop?
                if (i == row_x) 
                    continue; // Skips the row "row_x" that we need to remove
                subMatrix[sub_i] = (double*)malloc((a_cols - 1) * sizeof(double)); // Allocates memory for each row (which points to columns)
                if (subMatrix[sub_i] == NULL) 
                    return NULL; // Memory allocation check
                    for (uint32_t j = 0, sub_j = 0; j < a_cols; j++) { // Loops over columns to build matrix (original columns minus 1)
                        if (j == col_y) 
                            continue; // Skips column being removed
                        subMatrix[sub_i][sub_j] = a[i][j]; // Allocates memory for each column
                        sub_j++; // Increments through for loop (i)
                    }
                sub_i++; // Increments through for loop (j)
            }
            return subMatrix; // Returns the dynamically allocated submatrix
            // Matrix freed for you don't call free pointer!!
}
