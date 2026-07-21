#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N; cin >> N;
  ll MIN=10e9+1;
  int count=1;
  ll sum=0;
  for(int i=0;i<N;i++){
    ll a; cin >> a;
    sum+=abs(a);
    if(a<0){
      count*=-1;
    }
    MIN=min(MIN,abs(a));
  }
  if(count==-1){
    sum-=2*MIN;
  }
  cout << sum << endl;
  return 0;
}
