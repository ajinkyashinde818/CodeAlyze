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

ll MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;

  bool dir[2 * N];
  dir[0] = true;
  for(int i = 1; i < 2 * N; i++){
    if(s[i] != s[i-1]) dir[i] = dir[i-1];
    else dir[i] = !dir[i-1];
  }

  if(s[0] == 'W'){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1LL;
  ll cnt = 0;
  for(int i = 0; i < 2 * N; i++){
    if(dir[i]) cnt++;
    else{
      ans *= cnt;
      cnt--;
      ans %= MOD;
    }
  }

  for(ll i = 1; i <= N; i++){
    ans *= i;
    ans %= MOD;
  }

  if(cnt == 0){
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
