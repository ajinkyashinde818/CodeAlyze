#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{66, 18, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
