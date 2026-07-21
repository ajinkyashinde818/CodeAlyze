#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n;
  cin >>r >> g >> b >> n ;
  int ans=0;
  for(int i=0;i<=3000;i++){
    for(int q=0;q<=3000;q++){
      int as =n-r*i-q*g;
     if(as>=0 && as%b == 0){ans++;}
    }
  }
  cout << ans << endl;
}
