#include <iostream>
int main()
{
    int data[] = { 76, 13, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
