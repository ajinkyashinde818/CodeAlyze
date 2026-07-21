#include<bits/stdc++.h>
using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  long long count=0;
  for(int i=0; i<=N/R; i++){
    if(i*R>N) break;
    if(i*R==N){
      count++;
      continue;
    }
    for(int j=0; j<=N/G; j++){
      if(i*R+j*G>N) break;
      if(i*R+j*G==N) count++;
      else if((N-i*R-j*G)%B==0) count++;
    }
  }
  cout << count << endl;
  return 0;
}
