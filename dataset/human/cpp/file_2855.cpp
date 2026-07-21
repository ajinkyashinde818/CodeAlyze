#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int n;cin>>n;
  std::vector<ll> v(n);

  bool zero=false;
  ll sum=0;
  ll mn=(1ll<<50);
  ll cnt=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=abs(v[i]);
    mn = min(mn, abs(v[i]));
    if(v[i]<0)cnt++;
    if(v[i]==0){
      zero=true;
    }
  }
  if(zero || ((cnt % 2) ==0)){
    cout<<sum<<endl;
  }else{
    cout<<sum-2*mn<<endl;
  }

  return 0;
}
