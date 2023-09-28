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

	// Sort the container
	sort(begin(values), end(values));

	while (true) {
		std::cout << "Enter a number to find (0 to quit): ";
		int number;
		std::cin >> number;
		if (number == 0) {
			break;
		}
		if (binary_search(cbegin(values), cend(values), number)) {
			std::cout << "That number is in the vector." << std::endl;
		}
		else {
			std::cout << "That number is not in the vector." << std::endl;
		}
	}

	return 0;
}
