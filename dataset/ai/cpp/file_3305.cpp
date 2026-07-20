#include <iostream>
int main()
{
    int data[] = { 16, 15, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
