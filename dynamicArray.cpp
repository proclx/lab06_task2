#include <iostream>
#include "dynamicArray.h"

int** create_matrix_malloc(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = (int**)malloc(n * sizeof(int*));
    // побудова фінального вигляду матриці
    for (unsigned i = 0; i < n; i++) matrix[i] = (int*)malloc(m * sizeof(int));
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> matrix[i][j];
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) matrix[i][j] = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}

int** create_matrix_calloc(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = (int**)calloc(n, sizeof(int*));
    // побудова фінального вигляду матриці 
    for (int i = 0; i < n; i++) matrix[i] = (int*)calloc(m, sizeof(int));
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> matrix[i][j];
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) matrix[i][j] = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}

int** create_matrix_new(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = new int* [n];
    // побудова фінального вигляду матриці
    for (unsigned i = 0; i < n; ++i) matrix[i] = new int[m];
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> matrix[i][j];
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) matrix[i][j] = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}

int** matrixCreator(const unsigned n, const unsigned m, const char type)
{
    unsigned ch; std::cout << "How do you want to create matrix? \n1. via calloc\n2. via malloc\n3. via new\n"; std::cin >> ch;
    switch (ch)
    {
    case 1:
        return create_matrix_calloc(n, m, type);
    case 2:
        return create_matrix_malloc(n, m, type);
    case 3:
        return create_matrix_new(n, m, type);
    }
}

void printMatrix(int** matrix, const unsigned n, const unsigned m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

unsigned* pos_and_mul_of_six(int** matrix, const unsigned n, const unsigned m, unsigned& list_len)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            if (matrix[i][j] >= 0 && matrix[i][j] % 6 == 0)
            {
                ++list_len;
            }
        }
    }
    unsigned* result = new unsigned[list_len];
    unsigned result_index = 0;
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            if (matrix[i][j] >= 0 && matrix[i][j] % 6 == 0)
            {
                result[result_index] = matrix[i][j];
                ++result_index;
            }
        }
    }
    return result;
}

int** create_matrix_malloc_ptr(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = (int**)malloc(n * sizeof(int*));
    // побудова фінального вигляду матриці
    for (unsigned i = 0; i < n; i++) *(matrix + i) = (int*)malloc(m * sizeof(int));
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> *(*(matrix + i) + j);
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) *(*(matrix + i) + j) = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}
int** create_matrix_calloc_ptr(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = (int**)calloc(n, sizeof(int*));
    // побудова фінального вигляду матриці 
    for (unsigned i = 0; i < n; i++) *(matrix + i) = (int*)malloc(m * sizeof(int));
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> *(*(matrix + i) + j);
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) *(*(matrix + i) + j) = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}
int** create_matrix_new_ptr(const unsigned n, const unsigned m, const char type)
{
    // побудова рядків матриці
    int** matrix = new int* [n];
    // побудова фінального вигляду матриці
    for (unsigned i = 0; i < n; ++i) *(matrix + i) = new int[m];
    switch (type)
    {
        // користувач захотів ввести з клавіатури
    case 'i':
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                std::cin >> *(*(matrix + i) + j);
            }
        }
        break;
        // користувач захотів заповнити матрицю випадковими числами
    case 'r':
        const int M = 20;
        const int N = 25;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < m; ++j)
            {
                for (unsigned _rand_ = 0; _rand_ < M; ++_rand_) for (unsigned _rand = 0; _rand < N; ++_rand) *(*(matrix + i) + j) = rand() % 100;
            }
        }
        break;
    }
    return matrix;
}

int** matrixCreator_ptr(const unsigned n, const unsigned m, const char type)
{
    unsigned ch; std::cout << "How do you want to create matrix? \n1. via calloc\n2. via malloc\n3. via new\n"; std::cin >> ch;
    switch (ch)
    {
    case 1:
        return create_matrix_calloc_ptr(n, m, type);
    case 2:
        return create_matrix_malloc_ptr(n, m, type);
    case 3:
        return create_matrix_new_ptr(n, m, type);
    }
}

void printMatrix_ptr(int** matrix, const unsigned n, const unsigned m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            std::cout << *(*(matrix + i) + j) << ' ';
        }
        std::cout << std::endl;
    }
}

unsigned* pos_and_mul_of_six_ptr(int** matrix, const unsigned n, const unsigned m, unsigned& list_len)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            if (*(*(matrix + i) + j) >= 0 && *(*(matrix + i) + j) % 6 == 0)
            {
                ++list_len;
            }
        }
    }
    unsigned* result = new unsigned[list_len];
    unsigned result_index = 0;
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            if (*(*(matrix + i) + j) >= 0 && *(*(matrix + i) + j) % 6 == 0)
            {
                result[result_index] = *(*(matrix + i) + j);
                ++result_index;
            }
        }
    }
    return result;
}