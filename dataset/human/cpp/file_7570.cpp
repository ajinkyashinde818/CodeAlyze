#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long> a(n);
  for(int i=0; i<n; i++)cin>>a.at(i);

  long long x,y=0;
  x=a.at(0);
  for(int i=1; i<n; i++)y+=a.at(i);

  long long ans=abs(x-y);

  for(int i=1; i<n-1; i++){
    x+=a.at(i);
    y-=a.at(i);
    ans=min(ans, abs(x-y));
  }
  cout<<ans<<endl;
}
