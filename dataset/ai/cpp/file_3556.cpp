/* Standalone example. */
#include <iostream>
int main() {
    int data[] = { 89, 18, 8 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
