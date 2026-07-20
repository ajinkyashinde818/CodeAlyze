#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{3, 9, 5};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
