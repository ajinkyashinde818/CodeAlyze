#include<bits/stdc++.h>
using namespace std;

int main (void){
  int n,d,ans = 0;
  int R,G,B;
  cin >> R >> G >> B >> n;

  for(int i = 0;i <= n/R;i++){
    for(int j = 0;j <= n/G;j++){
      d = R*i + G*j;
      if((n-d) % B == 0 && n >= d){
        ans++;
      }
      }
    }

  cout << ans << "\n";
  return 0;
}
