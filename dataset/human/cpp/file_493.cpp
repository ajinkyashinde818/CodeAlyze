#include <iostream>
#include <vector>
//#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
  int r, g, b, n, ans=0, tmp;
  
  cin >> r >> g >> b >> n;
  
  if(r<g) {
    tmp = r;
    r = g;
    g = tmp;
  }
  if(r<b) {
    tmp = r;
    r = b;
    b = tmp;
  }
  
  if(g<b) {
    tmp = g;
    g = b;
    b = tmp;
  }
  

  for (int i=0; i<=n/r; i++) {
    for (int j=0; j<=(n-r*i)/g; j++) {
      if((n-r*i-g*j)%b==0) ans++;

    }
  }
  
  cout << ans <<endl;
}
