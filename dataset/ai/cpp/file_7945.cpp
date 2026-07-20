/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{57, 25, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
