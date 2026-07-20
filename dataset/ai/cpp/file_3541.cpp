#include <iostream>
int main() {
    int data[] = { 74, 3, 7 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
