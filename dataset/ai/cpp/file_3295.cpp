#include <iostream>
int main()
{
    int data[] = { 6, 5, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
