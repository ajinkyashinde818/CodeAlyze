// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v) { cout << v << endl; }
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int n; cin >> n;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  ll sum = 0;
  bool zero = false;
  ll min_v = 100000000000000000;
  ll minus = 0;
  for (auto &&a: A) {
    ll v = abs(a);
    sum += v;
    zero |= a == 0;
    minus += a<0;
    if (min_v > v) min_v = v;
  }
  if (zero or minus%2==0) print(sum);
  else print(sum-2*min_v);
  return 0;
}
