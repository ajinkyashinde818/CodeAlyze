#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{80, 5, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
