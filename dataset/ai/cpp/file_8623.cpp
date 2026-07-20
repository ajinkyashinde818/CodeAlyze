#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{55, 19, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
