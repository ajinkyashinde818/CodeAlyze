#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{60, 16, 5};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
