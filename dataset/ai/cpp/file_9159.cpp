#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{48, 16, 6};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
