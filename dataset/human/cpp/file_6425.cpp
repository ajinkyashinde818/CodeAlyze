#include <iostream>
using namespace std;
typedef long long ll;
ll mod=1e9+7;


int main(){
  ll n;
  string s;
  cin >> n >> s;
  int check=0;
  int x[2*n];
  for(int i=0;i<2*n;i++){
    if(s[i]=='B'&&check%2==0||s[i]=='W'&&check%2==1){
      check++; x[i]=0;
    }
    else{
      check--; x[i]=1;
    }
    cerr << check << endl;
  }
  if(check){
    cout << 0 << endl;
    return 0;
  }
  ll ans=1;
  for(ll i=1;i<=n;i++){
    ans*=i; ans%=mod;
  }
  ll cnt=0;
  for(ll i=2*n-1;i>=0;i--){
    if(x[i]) cnt++;
    else{
      ans*=cnt; ans%=mod; cnt--;
    }
  }
  cout << ans << endl;
}
