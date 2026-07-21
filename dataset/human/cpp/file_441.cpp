#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  int ans=0;
  for(int i=0;i<=3000;i++)
    for(int j=0;j<=3000;j++){
      int a=i*r+j*g;
      if(n>=a&&(n-a)%b==0)ans++;
    }
  cout<<ans<<endl;
}
