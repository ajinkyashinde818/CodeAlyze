#include <iostream>
int main()
{
    int data[] = { 32, 7, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
