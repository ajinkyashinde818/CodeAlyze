#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int64_t ans=0;
  for(int i=0;;i++){
    if(R*i>N){
      break;
    }
    for(int j=0;;j++){
      if(R*i+G*j>N){
        break;
      }
      if((N-R*i-G*j)%B==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
