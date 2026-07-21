#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
int main(){
  ll r,g,b,n;
  cin>>r>>g>>b>>n;
  ll ans=0;
  for(ll i=0;i<=n/r;i++){
    for(ll j=0;j<=n/g;j++){
      ll nokori=n-(i*r+j*g);
      if(nokori>=0&&nokori%b==0){
        ans++;
        //cout<<i<<" "<<j<<" "<<nokori/b<<endl;
      }
    }
  }
  cout<<ans<<endl;
}
