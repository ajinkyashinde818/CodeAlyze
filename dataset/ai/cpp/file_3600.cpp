#include <iostream>
int main()
{
    int data[] = { 44, 31, 3 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
