#include <iostream>
int main()
{
    int data[] = { 21, 20, 7 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
