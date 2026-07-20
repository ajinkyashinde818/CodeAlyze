/* Standalone example. */
#include <iostream>
int main()
{
    int terms = 17, previous = 0, current = 1;
    for (int step = 2; step <= terms; ++step)
{
        int next = previous + current; previous = current; current = next;
    }
    std::cout << current << '\n';
}
