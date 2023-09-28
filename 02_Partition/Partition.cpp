#include <algorithm>
#include <vector>
#include <iostream>

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	while (true) {
		std::cout << "Enter a number (0 to quit): ";
		int value;
		std::cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

int main()
{
	std::vector<int> values;

	populateContainer(values);

	partition(begin(values), end(values), [](int i) { return i % 2 == 0; });

	std::cout << "Partitioned result: ";
	for (const auto& i : values) { std::cout << i << " "; }
	std::cout << std::endl;

	return 0;
}
