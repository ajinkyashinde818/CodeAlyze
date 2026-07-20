#include <iostream>
int main()
{
    for (int row = 1; row <= 4; ++row)
{
        for (int column = 1; column <= row; ++column)
{
            std::cout << column << ' ';
        }
        std::cout << '\n';
    }
}
