#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector values{ 1, 2, 3 };
	auto result1{ std::ranges::find(cbegin(values), cend(values), 2) };
	if (result1 != cend(values)) {
		std::cout << *result1 << std::endl;
	}

	auto result2{ std::ranges::find(values, 2) };
	if (result2 != cend(values)) {
		std::cout << *result2 << std::endl;
	}

	return 0;
}