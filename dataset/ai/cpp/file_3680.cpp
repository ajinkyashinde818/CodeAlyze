#include <iostream>
int main()
{
    int data[] = { 35, 18, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
