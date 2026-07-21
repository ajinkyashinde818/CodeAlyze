#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n,tmp;
  cin >> n;
  ll a[n],sum[n],ans=100000000000;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum[i]=a[i];
    if(i!=0){
      sum[i]+=sum[i-1];
    }
  }
  for(int i=0;i<n-1;i++){
    tmp = abs(sum[i]-(sum[n-1]-sum[i]));
    ans = min(ans,tmp);
  }
  cout << ans<<endl;
}
