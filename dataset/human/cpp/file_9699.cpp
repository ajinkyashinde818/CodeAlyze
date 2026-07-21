#include<bits/stdc++.h>

using namespace std;

int alphabet[26];


const long long  MOD = 1e9 + 7;

int main(){
 int  N; cin >> N; string S; cin >> S;
 for(int i = 0; i < 26; i++){ alphabet[i] = 0;}
  
  for(int i = 0; i < N; i++){
    char c = S[i]; alphabet[c - 'a']++;} long long ans = 1;
  
  for(int i = 0; i < 26; i++){  ans *= (alphabet[i] + 1); ans %= MOD;}
  
  cout << ans - 1 << endl; return 0;}
