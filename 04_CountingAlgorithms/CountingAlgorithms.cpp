#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	
	// any_of()
	std::vector vec3{ 0, 0, 0, 0 };
	if (any_of(cbegin(vec3), cend(vec3), [](int i) { return i == 1; })) {
		std::cout << "At least one element == 1" << std::endl;
	}
	else {
		std::cout << "No elements are == 1" << std::endl;
	}

	return 0;
}
