#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

namespace ranges = std::ranges;

int main()
{
    std::vector<int> v(10, 2);
    std::partial_sum(v.cbegin(), v.cend(), v.begin());
    std::cout << "Entre los nombres: ";
    ranges::copy(v, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    auto DivisiblePor = [](int d)
    {
        return [d](int m) { return m % d == 0; };
    };

    if (ranges::any_of(v, DivisiblePor(7))) {
        std::cout << "Al menos un nombre es divisible por 7\n";
    }

    return 0;
}