#include <iostream>
int main() {
    int data[] = { 45, 32, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
