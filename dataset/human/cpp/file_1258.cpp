#include <bits/stdc++.h>
using namespace std;

int main(){
  int R, G, B, N;cin>>R>>G>>B>>N;
  int ans=0;

  for (int r=0;r<3001;++r){
    for (int g=0;g<3001;++g){
      if(N-R*r-G*g>=0&&((N-R*r-G*g)%B==0)) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
