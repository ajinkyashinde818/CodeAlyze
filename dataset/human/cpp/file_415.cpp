#include<bits/stdc++.h>
using namespace std;
int main(){
  int R,G,B,n;
  cin >> R >> G >>B >> n;
  int c = 0;
  int r = 0;
  while(R*r <= n) {
    int g = 0;
    while(R*r+G*g<=n) {
      if((n-R*r-G*g)%B==0){
        c += 1;
      }
      g += 1;
      
    }
    r+=1;
  }
  cout << c << endl;
}
