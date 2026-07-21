#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int n,a,b,c;
  cin >> a >> b >> c >> n;
  int now = 0;
  int res = 0;
  int r,g;
  r = 0;
  g = 0;
  while(1){
    if(now > n)break;
    while(1){
      if(now > n)break;
      if((n - now) % c == 0)res++;
      g++;
      now += b;
      //cout << now << endl;
    }
    r++;
    now = r * a;
    g = 0;
  }
  cout << res << endl;
}
