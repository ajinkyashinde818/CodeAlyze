#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      int rest = N - R * i - G * j;
      if(rest >= 0 && rest % B == 0) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
