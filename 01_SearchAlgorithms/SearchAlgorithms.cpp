#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	// The list of elements to be searched.
	std::vector myVector{ 5, 6, 9, 8, 8, 3 };
	auto beginIter{ cbegin(myVector) };
	auto endIter{ cend(myVector) };

	// Find the first element that does not satisfy the given lambda expression.
	auto it{ find_if_not(beginIter, endIter, [](int i) { return i < 8; }) };
	if (it != endIter) {
		std::cout << "First element not < 8 is " << *it << std::endl;
	}

	return 0;
}
