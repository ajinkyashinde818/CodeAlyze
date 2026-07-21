#include<bits/stdc++.h>
using namespace std;

int main(){
  long long q = 1000000000 + 7;
  long long n; cin >> n;
  string s; cin >> s;
  vector<long long> alpha(26, 0);
  for(long long i=0; i<n; i++){
    alpha[s[i]-'a']++;
  }
  long long ans=1;
  for(long long i=0; i<26; i++){
    if(alpha[i] != 0){
      ans = (ans*(alpha[i]+1)%q)%q;
    }
  }
  cout << (ans-1+q)%q << endl;
  return 0;
}
