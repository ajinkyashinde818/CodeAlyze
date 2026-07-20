/* Standalone example. */
#include <iostream>
using namespace std;
int main() {
  int terms = 5, previous = 0, current = 1;
  for (int step = 2; step <= terms; ++step) {
    int next = previous + current; previous = current; current = next;
  }
  cout << current << '\n';
}
