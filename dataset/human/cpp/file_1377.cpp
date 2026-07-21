#include <bits/stdc++.h>
using namespace std;
using ll=long long;
typedef pair<int,int>P;
 
int main() {
  ll r,g,b,n,count;
  cin>>r>>g>>b>>n;
  count=0;
  for(ll i=0;i<=n/r;i++){
    for(ll j=0;j<=(n-r*i)/g;j++){
      if(i*r+j*g>n){
        break;
      }
      else if((n-r*i-j*g)%b==0){
        count++;
      }
    }
  }
  cout<<count<<endl;
}
