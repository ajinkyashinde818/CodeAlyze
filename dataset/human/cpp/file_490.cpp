#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  int cnt=0;
  for(int r=0;r<=(3000/R)+1;r++){
    for(int g=0;g<=(3000/G)+1;g++){
      if((N-r*R-g*G)%B==0 && r*R+g*G<=N) cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
