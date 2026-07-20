#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{32, 31, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
