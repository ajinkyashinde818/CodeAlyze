#include <iostream>
int main() {
    int data[] = { 28, 3, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
