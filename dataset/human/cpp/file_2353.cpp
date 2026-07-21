#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> v;
  int ncnt = 0;
  int dmin = 1000000000;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
    if (a < 0) ncnt++;
    if (a >= 0 && dmin > a) dmin = a;
    if (a < 0 && dmin > -a) dmin = -a;
  }

  long long int result = 0;
  for (int i = 0; i < n; i++) {
    result += v[i] >= 0 ? v[i] : -v[i];
  }
  if (ncnt%2 == 1) result -= dmin*2;

  cout << result << endl;

  return 0;
}
