#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
typedef long long ll;
using namespace std;

int main(){
  ll i,j,k,r,g,b,n;
  cin >> r >> g >> b >> n;
  ll ret=0;
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      if(n-i*r-j*g>=0 && (n-i*r-j*g)%b==0)ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
