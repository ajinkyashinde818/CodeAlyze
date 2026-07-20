#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{74, 11, 4};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
