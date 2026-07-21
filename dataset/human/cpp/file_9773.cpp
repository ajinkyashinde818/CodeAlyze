#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int a[1000];
ll M = 1e9 + 7;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  for(int i = 0; i < N; i++){
    int t = S[i];
    a[t]++;
  }
  ll ans = 1;
  for(int i = 'a'; i <= 'z'; i++){
    ans = ans*(a[i] + 1) %M;
  }
  ans--;
  cout << ans << endl;
  return 0;
}
