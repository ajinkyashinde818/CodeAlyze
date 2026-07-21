#include<bits/stdc++.h>
using namespace std;
int main() {
  int R, G, B, N, ans=0; cin >> R >> G >> B >> N;
  for (int i=0; i<=N/R; i++) {
    for (int j=0; j<=N/G; j++) {
      int res = N-R*i-G*j;
      if(res%B==0&&res>=0) ans++;
    }
  }
  cout << ans << "\n";
}
