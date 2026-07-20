#include <iostream>
int main()
{
    int data[] = { 27, 22, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
