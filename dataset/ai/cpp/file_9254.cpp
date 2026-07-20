/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{54, 18, 3};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
