#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
   int N;
   string S;
   cin >> N >> S;

   map<char, int> log;

   for (int i = 0; i < N; i++) {
      log[S[i]]++;   
   }
   ll ans = 1;
   for (auto it = log.begin(); it!= log.end(); it++) {
      ans *= (it->second + 1);
      ans %= MOD;
   }
   cout << ans - 1 << endl;
   return 0;
}
