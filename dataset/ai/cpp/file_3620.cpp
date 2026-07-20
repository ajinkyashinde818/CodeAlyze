#include <iostream>
int main()
{
    int data[] = { 64, 20, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
