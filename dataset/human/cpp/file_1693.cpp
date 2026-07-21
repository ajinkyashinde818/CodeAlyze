#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;
ul over = 1000000007;

mt19937 mt(time(nullptr));
// uniform_int_distribution< int > rand_int(0, 10) // rand[0, 10] inclusive

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  int n;
  cin >> n;
  for (int i=1; i*(i+1)<=n*2; ++i) {
    if (i*(i+1)==n*2) {
      cout << "Yes" << endl;
      cout << i+1 << endl;
      for (int j=0; j<i+1; ++j) {
        cout << i;
        int p = j;
        for (int k=0; k<j; ++k) {
          cout << " " << p;
          p += i-k-1;
        }
        for (int k=j; k<i; ++k) {
          p++;
          cout << " " << p;
        }
        cout << endl;
      }
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
