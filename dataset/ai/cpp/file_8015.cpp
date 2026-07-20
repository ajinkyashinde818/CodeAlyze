/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{38, 2, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
