#include<bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,n; cin>>R >>G >>B >>n;
  int ans=0;
  for(int r=0;r<=3000;r++){
    for(int g=0;g<=3000;g++){
      int b=r*R+g*G;
      if(n>=b && (n-b)%B==0)ans++;
    }
  }
  cout<<ans<<endl;
}
