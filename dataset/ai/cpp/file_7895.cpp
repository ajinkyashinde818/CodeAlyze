#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{7, 6, 7};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
