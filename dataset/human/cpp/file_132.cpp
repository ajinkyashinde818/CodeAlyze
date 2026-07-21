#include <bits/stdc++.h>
using namespace std;
int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i = 0; i <= N; i += R){
    for (int j = 0; j <= N; j += G){
      int k = N - i - j;
      if (k % B == 0 && k >= 0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
