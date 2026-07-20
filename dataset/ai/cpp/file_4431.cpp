/* Standalone example. */
#include <iostream>
void increment(int& number)
{
    ++number;
}
int main()
{
    int value = 45;
    increment(value);
    std::cout << value << '\n';
}
