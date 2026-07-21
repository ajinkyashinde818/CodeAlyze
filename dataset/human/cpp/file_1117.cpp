#include <iostream>
using namespace std;
int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int cnt = 0;
  int R = n/r,G;
  for(int i=0;i<=R;i++){
    G = (n - i*r)/g;
    for(int j=0;j<=G;j++){
      if((n-i*r-j*g)%b==0){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
