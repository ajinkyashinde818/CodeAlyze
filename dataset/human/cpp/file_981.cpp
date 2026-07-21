#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c,int n){
  int ans=0;
  for(int i=0;i<=n/a;i++){
    for(int j=0;j<=(n-i*a)/b;j++){
      if((n-i*a-j*b)%c==0){
        ans++;
        //cout << i << "#" << j << "#" << endl;
      }
    }
  }
  return ans;
}

int main(){
  int a,b,c,n,ans;
  cin >> a >> b >> c >> n;
  ans=solve(a,b,c,n);
  cout << ans << endl;
  return 0;
}
