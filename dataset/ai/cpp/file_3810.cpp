#include <iostream>
int main()
{
    int data[] = { 76, 24, 3 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
