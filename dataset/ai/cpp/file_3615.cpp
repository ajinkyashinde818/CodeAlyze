#include <iostream>
int main()
{
    int data[] = { 59, 15, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
