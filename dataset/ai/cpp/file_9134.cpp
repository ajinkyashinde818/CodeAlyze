#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{23, 22, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
