#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{39, 3, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
