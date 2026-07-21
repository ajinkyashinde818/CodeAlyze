#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int r,g,b,n,cnt,ans=0;
  cin >> r >> g >> b >> n;
  for(int i=0; i<=n/r; i++) {
    for(int j=0; j<=n/g; j++) {
      cnt=n-r*i-g*j;
      if(cnt%b==0&&cnt>=0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
