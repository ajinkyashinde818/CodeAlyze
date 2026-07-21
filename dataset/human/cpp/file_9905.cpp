#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  map<char, int> cnt;
  for(int i = 0; i < n; i++){
    char now = s.at(i);
    cnt[now]++;
  }
  
  long long ans = 1, mod = pow(10,9) + 7;
  for(auto now : cnt) ans = ans * ++now.second % mod;
  
  ans = (ans + mod -1) % mod;
  cout << ans << endl;
}
