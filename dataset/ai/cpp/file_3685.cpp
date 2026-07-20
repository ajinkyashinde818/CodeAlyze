#include <iostream>
int main()
{
    int data[] = { 40, 23, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
