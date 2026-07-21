#include <iostream>
using namespace std;

int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int cnt=0;
  for(int i=0; i<=n/r; i++){
    for(int j=0; j<=n/g; j++){
      if(n-r*i-g*j>=0 && (n-r*i-g*j)%b==0)cnt++;
    }
  }
  cout << cnt;
  return 0;
}
