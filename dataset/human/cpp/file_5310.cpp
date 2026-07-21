/**
class cfmaster {
 public:
  struct code {
  	see the details down there !
  };
};
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  if (n >= 10) {
    cout << r << '\n';
  } else {
    cout << 100 * (10 - n) + r << '\n';
  }
  return 0;
}
