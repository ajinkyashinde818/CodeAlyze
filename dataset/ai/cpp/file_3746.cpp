#include <iostream>
int main() {
    int data[] = { 12, 22, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
