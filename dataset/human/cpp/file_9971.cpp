#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N,ans=1;
  int c[26]={};
  string S;

  cin >> N >> S;

  for(int i=0; i<N; i++){
    c[S[i]-'a']++; 					//count
  }
  for(int i:c){
    ans *= i+1;
    ans %= 1000000007;
  }
    
  cout << ans-1 << endl;
  return 0;
}
