#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;


int main(){
    ll n,cnt=0,sum=0;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
      cin >> a[i];
      if(a[i]<0)    cnt++;
      a[i] = abs(a[i]);
      sum+=a[i];
    }
    sort(a.begin(),a.end());
    if(cnt%2==0)    cout << sum;
    else    cout << sum-(2*a[0]);
    return 0;
}
