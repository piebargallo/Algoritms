#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> myVector;
	while (true) {
		std::cout << "Enter a test score to add (0 to stop): ";
		int score;
		std::cin >> score;
		if (score == 0) {
			break;
		}
		myVector.push_back(score);
	}

	auto endIt{ cend(myVector) };
	auto it{ find_if(cbegin(myVector), endIt, [](int i) { return i >= 100; }) };
	if (it == endIt) {
		std::cout << "No perfect scores" << std::endl;
	}
	else {
		std::cout << "Found a \"perfect\" score of " << *it << std::endl;
	}
	return 0;
}
