#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long a[n], v[n], f = 0, sum = 0, min = (int)1e9;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] < 0) f += 1; 
    v[i] = (a[i] > 0 ? a[i] : - a[i]);
    sum += v[i];
    if(v[i] < min) min = v[i];
  }
  cout << sum - (f % 2 ? 2 * min : 0) << endl;
  return 0;
}
