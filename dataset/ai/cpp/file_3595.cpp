#include <iostream>
int main()
{
    int data[] = { 39, 26, 5 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
