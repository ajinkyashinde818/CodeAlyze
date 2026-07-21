#include <bits/stdc++.h>
using namespace std;

int R,G,B,N;
int main(void){
  cin>>R>>G>>B>>N;
  int cnt=0;
  for(int r=0;r<3001;r++){
    for(int g=0;g<3001;g++){
      int M = r*R+g*G;
      if(M>N) break;
      if((N-M)%B==0) cnt++;
    }
    if(r*R>N) break;
  }
  cout << cnt << endl;
  return 0;
}
