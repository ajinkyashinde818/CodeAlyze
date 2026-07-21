#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;


typedef long long ll;

int N,M,H,W,K,A,B,S,T;
int a,b;

using namespace std;


int main() {
  cin >> N;
  ll ans = 0;
  vector<ll> a(N,0),b(N,0);
  for(int i =0;i < N;i++) cin >> a.at(i);
  sort(a.begin(),a.end());
  for(int i =0;i < N;i++){
    b.at(i) = a.at(i);
    if(a.at(i) < 0)b.at(i) = (-1) * a.at(i);
    ans += b.at(i);
  }
  sort(b.begin(),b.end());
  
  for(int i =0;i < N;i++) {
    //cout << a.at(i) << endl;
    if(a.at(i) >= 0){
      if(i%2 == 0) break;
      ans -= 2*b.at(0);
    }
    if(i%2 == 0 && i == N-1) ans -= 2*b.at(0);
  }
  
  
  cout << ans << endl;
}
