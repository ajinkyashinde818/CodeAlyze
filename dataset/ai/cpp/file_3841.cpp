#include <iostream>
int main() {
    int data[] = { 18, 24, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
