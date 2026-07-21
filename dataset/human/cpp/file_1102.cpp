#include<iostream>
using namespace std;
int R,G,B,N,ans;
int main(){
  ans=0;
  cin >> R >> G >> B >> N;
  for (int i=0;i<=N/R;i++){
    for (int j=0;j<=N/G;j++){
      if ((i*R+j*G)<=N && (N-(i*R+j*G))%B==0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
