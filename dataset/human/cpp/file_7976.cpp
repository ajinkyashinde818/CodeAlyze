#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<long long> s(N + 1, 0);
  for (int i = 0; i < N; i++){
    s[i + 1] = s[i] + a[i];
  }
  long long sum = s[N];
  long long m = 1e15;
  for (int i = 1; i < N; i++){
    m = min(m, abs(s[i] - (sum - s[i])));
  }
  cout << m;
}
