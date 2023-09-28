#include <vector>
#include <numeric>
#include <iostream>

int main()
{
	std::vector<int> values(10);
	iota(begin(values), end(values), 5);
	for (auto& i : values) { std::cout << i << " "; }
	std::cout << std::endl;

	return 0;
}