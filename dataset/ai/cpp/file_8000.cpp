#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{23, 18, 7};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
