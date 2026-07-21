#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n,ans;
  ans=0;
  cin>>r>>g>>b>>n;

  for(int i=0;i<n/r+1;i++){
    for(int j=0;j<(n-r*i)/g+1;j++){
        if((n-r*i-g*j)%b==0){
          ans+=1;
        }
    }
  }
  cout<<ans<<endl;
}
