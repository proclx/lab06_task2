#pragma once
// task 2
// via index
int** create_matrix_malloc(const unsigned n, const unsigned m, const char type);
int** create_matrix_calloc(const unsigned n, const unsigned m, const char type);
int** create_matrix_new(const unsigned n, const unsigned m, const char type);
int** matrixCreator(const unsigned n, const unsigned m, const char type);
void printMatrix(int** matrix, const unsigned n, const unsigned m);
unsigned* pos_and_mul_of_six(int** matrix, const unsigned n, const unsigned m, unsigned& list_len);
// via ptr
int** create_matrix_malloc_ptr(const unsigned n, const unsigned m, const char type);
int** create_matrix_calloc_ptr(const unsigned n, const unsigned m, const char type);
int** create_matrix_new_ptr(const unsigned n, const unsigned m, const char type);
int** matrixCreator_ptr(const unsigned n, const unsigned m, const char type);
void printMatrix_ptr(int** matrix, const unsigned n, const unsigned m);
unsigned* pos_and_mul_of_six_ptr(int** matrix, const unsigned n, const unsigned m, unsigned& list_len);