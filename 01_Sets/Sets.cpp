#include <algorithm>
#include <iostream>
#include <vector>
#include<string_view>

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

template<typename Iterator>
void DumpRange(std::string_view message, Iterator begin, Iterator end)
{
	std::cout << message;
	for_each(begin, end, [](const auto& element) { std::cout << element << " "; });
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec1, vec2, result;
	std::cout << "Enter elements for set 1:" << std::endl;
	populateContainer(vec1);
	std::cout << "Enter elements for set 2:" << std::endl;
	populateContainer(vec2);

	// set algorithms require sorted ranges
	sort(begin(vec1), end(vec1));
	sort(begin(vec2), end(vec2));

	DumpRange("Set 1: ", cbegin(vec1), cend(vec1));
	DumpRange("Set 2: ", cbegin(vec2), cend(vec2));

	result.resize(size(vec1) + size(vec2));
	
	auto newEnd = set_symmetric_difference(cbegin(vec1), cend(vec1),
		cbegin(vec2), cend(vec2), begin(result));
	DumpRange("The symmetric difference is: ", begin(result), newEnd);

	return 0;
}
