#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c,n,ans = 0;
  cin >> a >> b >> c >> n;
  for(int i = n/a ; ~i ; --i) 
    for(int j = (n-i*a)/b ; ~j ; --j) 
      if((n-i*a-j*b)%c == 0) 
        ++ans;
  cout << ans << endl;
  return 0;
}
