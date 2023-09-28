#include <vector>
#include <iostream>
#include <numeric>

int main()
{
	std::vector v1{ 1, 2, 3, 4 };
	std::vector v2{ 9, 8, 7, 6 };
	// (1*9) + (2*8) + (3*7) + (4*6) = 70
	std::cout << inner_product(cbegin(v1), cend(v1), cbegin(v2), 0) << std::endl;

	return 0;
}