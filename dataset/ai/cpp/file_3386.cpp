#include <iostream>
int main() {
    int data[] = { 8, 3, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
