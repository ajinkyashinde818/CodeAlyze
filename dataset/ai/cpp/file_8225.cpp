/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{70, 26, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
