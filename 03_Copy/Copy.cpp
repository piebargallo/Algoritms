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
	std::vector<int> vec1, vec2;

	populateContainer(vec1);

	vec2.resize(size(vec1));

	copy(cbegin(vec1), cend(vec1), begin(vec2));

	for (const auto& i : vec2) { std::cout << i << " "; }

	return 0;
}
