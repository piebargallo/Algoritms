#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>

int main()
{
    std::array s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    namespace ranges = std::ranges;

    ranges::sort(s);
    std::cout << ("Sort a ordination<: ");
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    ranges::sort(s, ranges::greater());
    std::cout <<"Sort using a standard library compare function object: ";
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;
    
    ranges::sort(s.begin(), s.end(), customLess);
    std:: cout << "Sort using a custom function object: ";
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    ranges::sort(s, [](int a, int b) { return a > b; });
    std:: cout << "Sort using a lambda expression: ";
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';
    
    return 0;
}