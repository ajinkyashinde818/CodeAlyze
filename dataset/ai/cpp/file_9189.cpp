#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{78, 15, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
