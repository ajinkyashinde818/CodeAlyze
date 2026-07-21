#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D; cin>>A>>B>>C>>D;
  int ans=0;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      if(D-i*A-j*B>=0&&(D-i*A-j*B)%C==0)ans++;
    }
  }
  cout<<ans<<endl;
}
