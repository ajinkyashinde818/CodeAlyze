#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main(){
  int N;cin>>N;
  vll A;
  for (int i=0;i<N;++i){
    ll a;cin>>a;A.push_back(a);
  }

  int cnt=0;
  int zero_flag=0;
  for (int i=0;i<N;++i){
    if(A[i]<0){cnt++;}
    if(A[i]==0){zero_flag=1;}
  }

  ll ans=0;
  for (int i=0;i<N;++i){
    ans+=abs(A[i]);
  }

  if(cnt%2==0|| zero_flag==1){
    cout << ans << endl;
    return 0;
  }

  ll abs_min=1e9;
  for (int i=0;i<N;++i){
    abs_min=min(abs_min, abs(A[i]));
  }
  cout << ans-2*abs_min << endl;
  return 0;
}
