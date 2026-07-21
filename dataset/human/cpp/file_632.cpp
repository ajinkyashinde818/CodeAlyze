#include<bits/stdc++.h>
using namespace std;

int main(void){
  int r, g, b, N;
  int nr,ng,nb;
  int c[3];
  int a = 0;

  cin >> c[0] >> c[1] >> c[2] >> N;
  sort(c,c+3);
  r = c[2];
  g = c[1];
  b = c[0];

  for(nr = 0; nr < (N/r)+1;nr++)
    for(ng = 0;ng < (N/g)+1;ng++)
      if( (N -r*nr - g*ng)%b == 0 && (N -r*nr - g*ng) >= 0){
        a++;
      }

  cout << a << endl;
}
