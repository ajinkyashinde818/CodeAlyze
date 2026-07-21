#include <bits/stdc++.h>
using namespace std;

void ioinit() { ios::sync_with_stdio(0); cin.tie(0); }

int main() {
  ioinit();
  int64_t N,sum = 0,min = INT_MAX;
  bool f = false;
  cin >> N;
  for(int i; i < N; i++){
  	int64_t a;
  	cin >> a;
    int64_t ab = abs(a);
    if(ab < min) min = ab;
    if(a < ab) f = !f;
    sum += ab;
  }
  if(f) sum -= min * 2;
  cout << sum << endl;
}
