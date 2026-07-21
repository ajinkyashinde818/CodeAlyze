#include <iostream>
using namespace std;
int main(){
  int R,G,B,N; cin >> R >> G >> B >> N;
  long long int ans=0;
  for(int r=0;r*R<=N;r++){
    for(int g=0;g*G<=(N-r*R);g++){
      int b=(N-r*R-g*G)/B;
      if((N-r*R-g*G-b*B)==0)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
