#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,n,ans=0;
  cin >> a >> b >> c >> n;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if((n-i*a-j*b)%c==0 and (n-i*a-j*b)>=0){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
