#include <algorithm>
#include <iostream>
#include <vector>
#include <execution>

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
	std::vector<int> myVector;
	populateContainer(myVector);

	std::cout << "Before sorting:" << std::endl;
	for (const auto& i : myVector) { std::cout << i << " "; }
	std::cout << std::endl;

	sort(std::execution::par, begin(myVector), end(myVector));

	std::cout << "After sorting:" << std::endl;
	for (const auto& i : myVector) { std::cout << i << " "; }
	std::cout << std::endl;

	return 0;
}
