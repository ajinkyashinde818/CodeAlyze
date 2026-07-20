#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{48, 12, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
