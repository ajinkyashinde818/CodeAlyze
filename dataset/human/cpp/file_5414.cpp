#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
    std::string str;
    int n, r;
    getline(std::cin, str, ' ');
    n = std::stoi(str);

    getline(std::cin, str);
    r = std::stoi(str);

    auto res = n >= 10? r : r + 100 * (10 - n);
    std::cout << res << std::endl;

    return 0;
}
