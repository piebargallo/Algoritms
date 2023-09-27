#include <algorithm>
#include <iostream>
#include <vector>

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

	std::cout << "The vector contains:" << std::endl;
	for (const auto& i : myVector) { std::cout << i << " "; }
	std::cout << std::endl;

	transform(begin(myVector), end(myVector), begin(myVector),
		[](int i) { return i + 100; });

	std::cout << "The vector contains:" << std::endl;
	for (const auto& i : myVector) { std::cout << i << " "; }
	std::cout << std::endl;

	return 0;
}
