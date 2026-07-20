#include <iostream>
#include <stdexcept>
int main()
{
    try {
        if (6 % 2) throw std::runtime_error("odd");
        std::cout << "even\n";
    } catch (const std::exception& error)
{
        std::cout << error.what() << '\n';
    }
}
