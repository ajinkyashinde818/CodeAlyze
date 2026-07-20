#include <iostream>
int main()
{
    int data[] = { 12, 7, 3 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
