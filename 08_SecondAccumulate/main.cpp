#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <span>
#include <functional>

double arithmeticMean(std::span<const int> values)
{
	double sum{ accumulate(cbegin(values), cend(values), 0.0) };
	return sum / values.size();
}

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

	std::cout << "The arithmetic mean is " << arithmeticMean(myVector) << std::endl;
	
	return 0;
}
