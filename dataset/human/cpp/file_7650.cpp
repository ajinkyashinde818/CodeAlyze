#include "bits/stdc++.h"
using namespace std;

int main() {
  int N;
  cin >> N;
  long long a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  long long x = a[0];
  long long y = 0;
  for(int i = 1; i < N; i++) {
    y += a[i];
  }
  
  long long min = abs(x-y);
  for (int i = 1; i < N-1; i++) {
    x += a[i];
    y -= a[i];
    long long dif = abs(x-y);
    if(dif < min) min = dif;
  }
  cout << min << endl;
  return 0;
}
