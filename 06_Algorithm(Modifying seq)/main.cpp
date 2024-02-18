#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> source(10);
    std::iota(source.begin(), source.end(), 0);

    std::vector<int> destination;

    std::ranges::copy(source.begin(), source.end(),
        std::back_inserter(destination));
    
    std::cout << "El destino contiene: ";

    std::ranges::copy(destination, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::cout << "Los impares en el destino son: ";

    std::ranges::copy_if(destination, std::ostream_iterator<int>(std::cout, " "),
        [](int x) { return (x % 2) == 1; });
    std::cout << '\n';

    return 0;
}