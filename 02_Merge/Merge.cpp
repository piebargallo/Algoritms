#include <algorithm>
#include <vector>
#include <iostream>
#include <string_view>

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
	std::vector<int> vectorOne, vectorTwo, vectorMerged;
	std::cout << "Enter values for first vector:" << std::endl;
	populateContainer(vectorOne);
	std::cout << "Enter values for second vector:" << std::endl;
	populateContainer(vectorTwo);

	// Sort both containers
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// Make sure the destination vector is large enough to hold the values
	// from both source vectors.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne), cbegin(vectorTwo),
		cend(vectorTwo), begin(vectorMerged));

	DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));

	return 0;
}
