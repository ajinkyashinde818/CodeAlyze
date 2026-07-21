#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long LL;
LL i,j,k,n,m;
LL mod=1000000007;
string s;

int main() {
  LL r,g,b;cin >>r>>g>>b>>n;
  int nr=n/r;
  int ng=n/g;
  int nb=n/b;
  int cnt = 0;
  for(i=0;i<nr+1;++i) {
    for(j=0;j<ng+1;++j) {
      int val = n -i*r - j*g;
      if (val < 0) continue;
      if(val%b==0) ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
