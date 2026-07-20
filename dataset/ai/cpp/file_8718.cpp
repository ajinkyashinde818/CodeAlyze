#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{61, 21, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
