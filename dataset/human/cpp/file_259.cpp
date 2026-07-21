#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  int ans=0;
  for(int i=0;i<n/a+1;i++){
    int x=(n-i*a)/b;
    for(int j=0;j<x+1;j++){
      if((n-i*a-j*b)%c==0)
        ans++;
    }
  }
  cout << ans << endl;
}
