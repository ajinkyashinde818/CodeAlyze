/* Standalone example. */
#include <iostream>
int main() {
    int data[] = { 38, 2, 8 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
