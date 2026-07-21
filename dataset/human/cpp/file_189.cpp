#include <bits/stdc++.h>
using namespace std;



int main() {
  int64_t R,G,B,N;
  cin>>R>>G>>B>>N;
  
  int64_t K=0;
  for(int r=0;r*R<=N;r++){
    for(int g=0;g*G<=N-r*R;g++){
      if(N-r*R-g*G==0){
        K++;
      }
      else{
        if((N-r*R-g*G)%B==0){
          K++;
        }
      }
    }
  }
  cout<<K<<endl;
    
}
