#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  long ans =0;
  for(int r=0;r<=N/R;r++){
    for(int g=0;g<=N/G;g++){
      int res=N-r*R-g*G;
      if(res<0) continue;
      //cout<<res<<endl;
      int buy=res/B;
      if(res-buy*B==0) ans++;
    }
  }
  cout<<ans<<endl;
}
