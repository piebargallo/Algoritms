#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>

int main()
{
    constexpr std::array v = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    std::cout << "v: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // Expresión lambda 
    int cuenta_div4 = std::count_if(v.begin(), v.end(), [](int i) {return i % 4 == 0; });
    std::cout << "nnombres divisible por cuatro: " << cuenta_div4 << '\n';

    return 0;
}