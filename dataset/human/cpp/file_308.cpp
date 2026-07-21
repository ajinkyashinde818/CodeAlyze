#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
  int R,G,B,N; cin>>R>>G>>B>>N;
  
  int ans=0;

  for(int r=0;r*R<=N;r++){
    for(int g=0;g*G+r*R<=N;g++){
      if((N-r*R-g*G)%B==0){
        ans++;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
