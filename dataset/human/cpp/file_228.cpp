#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for(int i=0;i<n/r+1;i++){
    int nn = n-r*i;
    for(int j=0;j<nn/g+1;j++){
      int nnn = nn-g*j;
      if(nnn%b==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
