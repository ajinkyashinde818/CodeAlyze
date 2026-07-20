#include <iostream>
int main() {
    int data[] = { 58, 2, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
