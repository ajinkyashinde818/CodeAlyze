#include <iostream>
int main() {
    int data[] = { 15, 2, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
