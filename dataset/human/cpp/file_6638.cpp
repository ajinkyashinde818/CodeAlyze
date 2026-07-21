#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int S[200005]={0};
bool T[200005]={0};

int main(){
  int n;
  cin>>n;
  ll ans=1;
  for(int i=1;i<=2*n;i++){
    char c;cin>>c;
    if(c=='B')S[i]=1;
    else S[i]=2;
  }
  if(S[1]==2){
    cout<<0<<endl;
    return 0;
  }
  T[1]=0;
  for(int i=2;i<=2*n;i++){
    if(S[i]!=S[i-1])T[i]=T[i-1];
    else if(T[i-1]==0)T[i]=1;
    else T[i]=0;
  }
  ll num=1;
  for(int i=2;i<=2*n;i++){
    if(T[i]==0)num++;
    else {
      ans=(ans*num)%MOD;
      num--;
    }
    if(num<0){
      cout<<0<<endl;
      return 0;
    }
  }
  if(num!=0){
    cout<<0<<endl;
    return 0;
  }
  for(int i=2;i<=n;i++){
    ans=(ans*i)%MOD;
  }
  cout<<ans<<endl;
}
