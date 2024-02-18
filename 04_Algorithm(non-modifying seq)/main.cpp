#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>

namespace ranges = std::ranges;

int main()
{
    constexpr std::array v = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10,11 };
    std::cout << "v: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // Expresión lambda 
    int num_items11 = ranges::count_if(v, [](int i) {return i % 11 == 0; });
    std::cout << "nombre de divisibles por once: " << num_items11 << '\n';

    return 0;
}