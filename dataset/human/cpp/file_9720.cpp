#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int64_t mod=1e9+7;
  vector<int> count(26,0);
  for(int i=0;i<N;i++){
    count.at(S.at(i)-'a')++;
  }
  int64_t ans=1;
  for(auto c:count){
    ans*=(c+1);
    ans%=mod;
  }
  ans-=1;
  if(ans<0){
    ans+=mod;
  }
  cout << ans << endl;
  return 0;
}
