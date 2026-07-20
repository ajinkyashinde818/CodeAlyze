#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{50, 14, 6};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
