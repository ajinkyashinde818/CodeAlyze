#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;
 
int main(){
  double R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans=0;
  for(int r=0; r*R<=N; r++){
    for(int g=0; g*G+r*R<=N; g++){
      int tmp=(N-r*R-g*G)/B;
      if(r*R+g*G+B*tmp==N) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
