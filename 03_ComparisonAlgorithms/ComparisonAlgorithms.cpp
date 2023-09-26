#include <algorithm>
#include <vector>
#include <list>
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
	std::vector<int> myVector;
	std::list<int> myList;

	std::cout << "Populate the vector:" << std::endl;
	populateContainer(myVector);
	std::cout << "Populate the list:" << std::endl;
	populateContainer(myList);

	// equal() and mismatch() accepting four iterators (since C++14)
	if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		std::cout << "The two containers have equal elements" << std::endl;
	}
	else {
		// If the containers were not equal, find out why not
		auto miss{ mismatch(cbegin(myVector), cend(myVector),
			cbegin(myList), cend(myList)) };
		std::cout << "The following initial elements are the same in "
			<< "the vector and the list:" << std::endl;
		for (auto i{ cbegin(myVector) }; i != miss.first; ++i) {
			std::cout << *i << '\t';
		}
		std::cout << std::endl;
	}

	return 0;
}