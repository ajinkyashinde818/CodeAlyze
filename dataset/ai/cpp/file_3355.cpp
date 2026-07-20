#include <iostream>
int main()
{
    int data[] = { 66, 3, 3 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
