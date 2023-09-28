#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::vector values{ 11, 22, 33, 44 };

	// Double each element in the values vector.
	for_each(begin(values), end(values), [](auto& value) { value *= 2; });

	// Print all the elements of the values vector.
	for_each(cbegin(values), cend(values), [](const auto& value) { std::cout << value << std::endl; });

	return 0;
}
