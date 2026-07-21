#include"bits/stdc++.h"
using namespace std;
int n;
string A;
bool open[(int)2e5+5];
int main(){
  cin>>n>>A;
  long long ans=1;
  int x = 0;
  const long long MOD=1e9+7;
  if(A[0]!='B') {cout<<0; return 0;}
  for(int i=0;i<2*n;++i){
    if(i==0||( (A[i]!=A[i-1]&&open[i-1]) || (A[i]==A[i-1]&&!open[i-1]) )){
      open[i]=1;++x;
    }else{
      ans*=x;
      ans%=MOD;
      --x;
    }
  }
  if(x) {cout<<0; return 0;}
  for(int i=1;i<=n;++i) ans*=i, ans%=MOD;
  cout << ans << '\n';
}
