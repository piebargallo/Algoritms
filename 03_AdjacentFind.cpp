/* 
	Posible solución algoritmo adjacent_find()

   Finds the instance of two consecutive elements that are equal to each other or are equivalent
   to each other as specifier by a predicate.
   
   Encuentra la instancia de dos elementos consecutivos si son iguales o equivalentes 
   entre sí, según lo especificado por un predicado.
   
   template <class ForwardIt>
   ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
   {
		if (first == last)
        return last;
 
		ForwardIt next = first;
		++next;

		for(; next != last; ++next, ++first)
			if(first != next)
				return first;
		return last;
	} 
*/

#include <vector> // std::vector
#include <iostream>
#include <algorithm> // adjacent_find

int main() {
	
	std::vector<int> v { 1, 4, 2, 8, 2, 2, 3, 4, 2 };

	// find in entire vector
	auto j = adjacent_find(begin(v), end(v));
	if (j != end(v)) {   // true => found
		auto const value = *j;  // int value = 2
		auto const index = distance(begin(v), j);  // index = 0
		std::cout << "value: " << value << '\n';
		std::cout << "index: " << index << '\n';
	}

	return 0;

}

