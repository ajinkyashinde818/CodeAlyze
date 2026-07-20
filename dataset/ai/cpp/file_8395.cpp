#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{62, 10, 3};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
