#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,n; cin >> r >> g >> b >> n;
  int cnt = 0;
  for(int i = 0; i <= n; i+=r){
    for(int j = 0; j <= n; j+=g){
      int x = i + j;
      if(n-x<0)continue;
      cnt += (n-x)%b==0;
    }
  }
  cout << cnt << endl;
}
