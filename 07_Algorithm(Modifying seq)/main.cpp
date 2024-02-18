#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
    std::string str = "#Optimiza #del #Valor #de #Retorno";
    std::cout << "before: " << std::quoted(str) << '\n';

    std::cout << "after:  \"";
    std::remove_copy(str.begin(), str.end(),
        std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";

    return 0;
}