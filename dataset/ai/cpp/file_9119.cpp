#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{8, 7, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
