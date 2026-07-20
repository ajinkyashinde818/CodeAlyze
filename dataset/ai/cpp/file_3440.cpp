#include <iostream>
int main()
{
    int data[] = { 62, 26, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
