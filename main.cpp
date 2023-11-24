#include <iostream>
#include "dynamicArray.h"

int main()
{
	const unsigned n = 10;
	const unsigned m = 10;
	char choice; std::cout << "To create matrix via console input press 'i', to create via random numbers 'r': "; std::cin >> choice;
	int** matrix = matrixCreator(n, m, choice);
	printMatrix(matrix, n, m);
	unsigned list_len = 0;
	unsigned* sat_numbers = pos_and_mul_of_six(matrix, n, m, list_len);
	std::cout << "All element that are positive and % 6 == 0: ";
	for (unsigned i = 0; i < list_len; ++i)
	{
		std::cout << sat_numbers[i] << ' ';
	}
	std::cout << "\nThe same task but via pointers\nTo create matrix via console input press 'i', to create via random numbers 'r': "; std::cin >> choice;
	int** matrix_ptr = matrixCreator_ptr(n, m, choice);
	printMatrix_ptr(matrix, n, m);
	unsigned list_len_ptr = 0;
	unsigned* sat_numbers_ptr = pos_and_mul_of_six(matrix, n, m, list_len_ptr);
	std::cout << "All element that are positive and % 6 == 0: ";
	for (unsigned i = 0; i < list_len_ptr; ++i)
	{
		std::cout << *(sat_numbers_ptr + i) << ' ';
	}
	std::cout << std::endl;
	return 0;
}