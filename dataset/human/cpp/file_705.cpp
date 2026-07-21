#include<bits/stdc++.h>
using namespace std;
int main(){
  int ans;
  int R,G,B,N,r,g;
  cin>>R>>G>>B>>N;
  for(int r=0;r<=N/R;r++){
    for(int g=0;g<=N/G;g++){
      int O=N-(r*R+g*G);
      if(O>=0 && O%B==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
