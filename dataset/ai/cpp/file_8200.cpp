#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{45, 32, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
