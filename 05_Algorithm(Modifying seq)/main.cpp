#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);

    std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(),
        std::back_inserter(to_vector));
    
    std::cout << "to_vector contiene: ";

    std::copy(to_vector.begin(), to_vector.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::cout << "Los impares en to_vector son: ";

    std::copy_if(to_vector.begin(), to_vector.end(),
        std::ostream_iterator<int>(std::cout, " "),
        [](int x) { return x % 2 != 0; });
    std::cout << '\n';

    return 0;
}