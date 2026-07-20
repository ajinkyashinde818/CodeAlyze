#include <iostream>
int main() {
    int data[] = { 69, 29, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
