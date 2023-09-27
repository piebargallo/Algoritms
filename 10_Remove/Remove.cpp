#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

void removeEmptyStrings(std::vector<std::string>& strings)
{
	auto it{ remove_if(begin(strings), end(strings),
		[](const std::string& str) { return str.empty(); }) };
	// Erase the removed elements.
	strings.erase(it, end(strings));
}

void removeEmptyStringsWithoutAlgorithms(std::vector<std::string>& strings)
{
	for (auto iter{ begin(strings) }; iter != end(strings); ) {
		if (iter->empty()) {
			iter = strings.erase(iter);
		}
		else {
			++iter;
		}
	}
}

int main()
{
	std::vector<std::string> myVector{ "", "one", "", "two", "three", "four" };

	for (auto& str : myVector) { std::cout << "\"" << str << "\"  "; }
	std::cout << std::endl;
	removeEmptyStrings(myVector);
	for (auto& str : myVector) { std::cout << "\"" << str << "\"  "; }
	std::cout << std::endl;

	return 0;
}
