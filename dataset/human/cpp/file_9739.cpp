#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;
  vector<int> char_cnt(26);
  for(int i = 0; i < S.length(); i++){
    char_cnt[S[i] - 'a']++;
  }
  long long ans = 1;
  const long long mod = 1e9 + 7;
  for(int i = 0; i < 26; i++){
    ans *= char_cnt[i] + 1;
    ans %= mod;
  }
  cout << ans - 1 << endl;
}
