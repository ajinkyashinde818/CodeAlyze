#include<iostream>
using namespace std;
int main(){
  int n,al[26] = {},i;long long ans = 1;char s;
  while(cin >> s) al[s-'a']++;
  for(i=0;i<26;i++) ans = (ans*(al[i]+1))%1000000007;
  ans--;
  if(ans<0) ans += 1000000007;
  cout << ans << endl;
}
