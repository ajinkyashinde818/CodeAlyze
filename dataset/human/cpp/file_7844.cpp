#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum=sum+a.at(i);
  }
  vector<ll> b(n-1);
  ll suma=0;
  for(int i=0;i<n-1;i++){
    suma=suma+a.at(i);
    b.at(i)=abs(2*suma-sum);
  }
  sort(b.begin(),b.end());
  cout << b.at(0) << endl;
}
