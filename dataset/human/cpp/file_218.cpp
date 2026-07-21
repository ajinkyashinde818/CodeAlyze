#include <iostream>

using namespace std;

int main(){
  int R, G, B, N, i, j, k, ans=0;
  cin >> R >> G >> B >> N;
  for(i=0; i<=N; i++){
    for(j=0; j<=N; j++){
      if(R*i + G*j > N) break;
      if((N-R*i-G*j) % B == 0){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
