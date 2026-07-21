#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans=0;
  ll count=0;
  ll small=1e9+1;
  for(int i=0;i<n;i++){
    if(a[i]<0){
      count++;
    }
    a[i]=abs(a[i]);
    small=min(small,a[i]);
    ans+=a[i];
  }
  if(count%2==0){
    cout << ans << endl;
  }
  else{
    cout << ans-small*2 << endl;
  }
}
