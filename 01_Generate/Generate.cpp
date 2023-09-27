#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector<int> values(10); // Create a vector of 10 elements.
	int value{ 1 };
	generate(begin(values), end(values), [&value] { value *= 2; return value; });
	for (const auto& i : values) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}