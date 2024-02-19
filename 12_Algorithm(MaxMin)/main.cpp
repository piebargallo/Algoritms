#include <algorithm>
#include <iostream>
#include <string> 

int main()
{
    std::cout << std::max({ "foo", "bar", "hello" },
        [](const std::string& s1, const std::string& s2) {
            return s1.size() < s2.size();
        }) << std::endl;

    return 0;
}