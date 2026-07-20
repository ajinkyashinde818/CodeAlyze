#include <iostream>
int main() {
    int data[] = { 47, 26, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
