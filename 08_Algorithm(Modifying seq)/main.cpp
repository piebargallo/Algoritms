#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    // Filtrar el símbolo hash de la cadena dada.
    const std::string_view str {"#Optimización #De #Búfer #Pequeño"};
    std::cout << "antes: " << std::quoted(str) << '\n';

    std::cout << "después:  \"";
    std::ranges::remove_copy(str.begin(), str.end(),
        std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";

    return 0;
}