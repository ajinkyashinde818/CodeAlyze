#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int i,j;
  int ans = 0;
  for(i=0;i<=n;i++){
    if(r*i>n)break;
    for(j=0;j<=n;j++){
      if(r*i+g*j>n)break;
      else if((n-r*i-g*j)%b==0)ans++;
    }
  }
  cout << ans << endl;
}
