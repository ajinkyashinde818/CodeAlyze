#include <bits/stdc++.h>
using namespace std;
int main(){
	int R,G,B,N,S,T,U,answer;
  
  double Z,X;
  answer =0;
  	cin >> R >> G >> B >> N;
    S = N/R;
  //cout << S << endl;
  	for(int i=0;i<S+1;i++){
      T = N-R*i;
      U = T/G;
     // cout << T << U << endl;
      for(int k=0;k<U+1;k++){
        X =T-G*k;
        Z=X/B;
        if(ceil(Z)== floor(Z)){
          if(Z>=0){
          answer++;
          }
        }
        else{continue;}
    }
    }
  cout << answer << endl;
}
