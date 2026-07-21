#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  int r, g, b, n;cin>>r>>g>>b>>n;
  int ans=0;
  if(r<g)swap(r, g);
  if(g<b)swap(g, b);
  for(int i=0;i<=(n/r);i++){
    for(int j=0;j<=((n-r*i)/g);j++){
      int num = n-r*i-g*j;
      ans += (num>=0 && num%b == 0);
    }
  }
  cout<<ans<<endl;
}
