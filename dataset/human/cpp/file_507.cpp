#include <bits/stdc++.h>
using namespace std;

int main(){

  int R,G,B,n;
  int r,g,b;
  cin >> R >> G >> B >> n;
  int ct = 0;
  int N;
  r = n/R;
  g = n/G;
  b = n/B;
  for(int i=0;i<=r;i++){
    for(int j=0;j<=g;j++){
      N = n-(i*R)-(j*G);
        if(N%B==0&&N>=0){
          ct++;
        }
    }
  }

  cout << ct << endl;

}
