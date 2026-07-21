#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll d[256];
int main() {
  ios::sync_with_stdio(false);
  int N;
  string S;
  cin >> N;
  cin >> S;
  for (int i=0; i<N; i++) {
    d[S[i]]++;
  }
  ll MOD = 1000000007LL;
  ll ret = 1;
  for (int i='a'; i<='z'; i++) {
    ret = (ret * (d[i] + 1LL)) % MOD;
  }
  ret--;
  cout << ret << endl;
}
