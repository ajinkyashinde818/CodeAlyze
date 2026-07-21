#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int mg,mb,mr,m=0;
  ll tot=0;
  mg = n / g;
  mb = n / b;
  mr = n / r;

  for (int i = 0;i<=mr;i++){
    for (int j = 0;j<=mg;j++){
      m = n - i*r - j*g;
      if (m >= 0 && m % b == 0){
	tot += 1;
      }
    }
  }
  cout << tot;
}
