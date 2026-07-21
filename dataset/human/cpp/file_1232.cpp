#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, j;
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int pat = 0;
  for(int r=0; r*R<=N; r++){
  int ball = 0;
    for(int g=0; r*R+g*G<=N; g++){
      ball = r*R + g*G;
      if((N-ball)/B>=0 && (N-ball)%B==0){
        pat++;
      }
    }
  }
  cout << pat << endl;
  return 0;
}
