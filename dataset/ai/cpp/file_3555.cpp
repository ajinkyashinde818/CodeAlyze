#include <iostream>
int main()
{
    int data[] = { 88, 17, 7 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
