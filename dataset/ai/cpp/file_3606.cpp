#include <iostream>
int main() {
    int data[] = { 50, 6, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
