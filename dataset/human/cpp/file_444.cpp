#include<bits/stdc++.h>
using namespace  std;
int main(){
  int R,G,B,n;
  cin >> R >> G >> B >> n;
  int rm,gm,bm;
  rm = n/R;
  gm = n/G;
  bm = n/B;
  int count=0;
  for (int i=0;i<=rm;i++){
    for (int j=0;j<=gm;j++){
      if (i*R+j*G > n) break;
      if ((n - (i*R + j*G)) % B == 0) count++;
    }
  }
  cout << count << endl;
}
