#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S, T;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  int count = 0;
  for(int i = 0; i<N; i++){
    ll a;
    cin >> a;
    A.at(i) = a;
    B.at(i) = abs(a);
    if(a < 0){
      count += 1;
    }
  }

  sort(B.begin(), B.end());
  ll ans = 0;
  if(count % 2 == 1){
    ans = B.at(0) * (-1);
    for(int i = 1; i<N; i++){
      ans += B.at(i);
    }
  }else{
    for(int i = 0; i<N; i++){
      ans += B.at(i);
    }
  }

  cout << ans << endl;


}
