#include<bits/stdc++.h>
using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int P=N/R+1;
  int Q=N/G+1;
  int S=N/B+1;
  int Ans=0;
  for(int r=0; r<=P; r++){
    for(int g=0; g<=Q; g++){
      if(r*R+g*G>N){
        break;
      }
      if((N-r*R-g*G)%B==0){
        Ans++;
      }
    }
  }
  cout << Ans << endl;
}
