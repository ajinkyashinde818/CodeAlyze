#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ll n;
  cin >> n;
  vector<ll>pos;
  vector<ll>neg;
  vector<ll>pos1;
  bool zero = false;
  for(int i=0; i<n; ++i){
    ll a;
    cin >> a;
    if(a>0){ pos.push_back(a);pos1.push_back(a);}
    else if(a<0){neg.push_back(a);pos1.push_back(abs(a));}
    else if(a==0)pos1.push_back(abs(a));
  }
  sort(neg.begin(), neg.end());
  sort(pos1.begin(), pos1.end());
  ll sum=0;
  for(int i=0; i<n; ++i){
    
    sum += pos1[i];
  }
 ll res = sum-pos1[0]*2;
  if(neg.size()%2==0)
    cout << sum << endl;
  else if(neg.size()%2!=0)
    cout << res << endl;
 
}
