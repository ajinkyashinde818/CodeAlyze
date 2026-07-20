#include <iostream>
int main()
{
    int data[] = { 75, 27, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
