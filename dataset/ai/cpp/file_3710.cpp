/* Standalone example. */
#include <iostream>
int main()
{
    int data[] = { 65, 17, 8 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
