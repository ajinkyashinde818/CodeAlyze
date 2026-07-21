#include<bits/stdc++.h>

using namespace std;

int main(){
  int cnt = 0;
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      int tmp = n - r*i - g*j;
      if (tmp % b == 0 && 0 <= tmp){
        cnt++;
      }
    }
  }
  cout << cnt << endl;

}
