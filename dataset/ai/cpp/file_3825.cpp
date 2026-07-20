#include <iostream>
int main()
{
    int data[] = { 91, 8, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
