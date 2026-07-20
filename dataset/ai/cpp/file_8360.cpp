#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{27, 6, 3};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
