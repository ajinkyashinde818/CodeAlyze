/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{48, 23, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
