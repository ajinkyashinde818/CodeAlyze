#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{67, 4, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
