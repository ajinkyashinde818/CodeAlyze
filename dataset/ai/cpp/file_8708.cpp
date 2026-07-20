/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{51, 11, 5};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
