#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{66, 26, 6};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
