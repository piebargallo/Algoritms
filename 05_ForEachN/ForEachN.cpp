#include <algorithm>
#include <map>
#include <iostream>

int main()
{
	std::map<int, int> myMap{ { 4, 40 }, { 5, 50 }, { 6, 60 } };
	for_each_n(cbegin(myMap), 2, [](const auto& p)
		{ std::cout << p.first << "->" << p.second << std::endl; });

	return 0;
}