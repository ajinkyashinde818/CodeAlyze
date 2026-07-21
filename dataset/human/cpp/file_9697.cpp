#include <bits/stdc++.h>

using namespace std;

const int mod=1000000007;

int main(){
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  vector<long> cnt(26,0);
  for(int i=0;i<n;i++) cnt[s[i]-'a']++;
  
  long res=1;
  for(int i=0;i<26;i++) {res*=(cnt[i]+1);
                         res%=mod;
                        }

  cout << res-1 << endl;
}
