#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{72, 20, 6};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
