#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  long long int X = 0, Y = 0;
  for (int i = 0; i < N; i++) X += A.at(i);
  
  long long int ans = 1000000000000000;
  for (int i = N - 1; i > 0; i--) {
    X -= A.at(i);
    Y += A.at(i);
    ans = min(ans, abs(X - Y));
  }
  
  cout << ans << endl;
}
