#include <algorithm>
#include <iostream>
#include <vector>
#include <format>

int main()
{
	// Using max() and min() on more than two values.
	int x1{ 2 }, x2{ 9 }, x3{ 3 }, x4{ 12 };
	
	// Using minmax() + C++17 structured bindings.
	auto [min1, max1] { std::minmax({ x1, x2, x3, x4 }) };
	std::cout << std::format("Minmax of 4 elements is <{},{}>", min1, max1) << std::endl;

	// Using minmax_element() + C++17 structured bindings.
	std::vector values{ 11, 33, 22 };
	auto [min2, max2] { minmax_element(cbegin(values), cend(values)) };
	std::cout << std::format("minmax_element() result: <{},{}>", *min2, *max2) << std::endl;

	return 0;
}

