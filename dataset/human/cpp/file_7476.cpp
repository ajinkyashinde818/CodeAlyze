#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  vector<long long int> accum(n+1);
  accum[0] = 0;
  
  for (long long int i = 0; i < n; i++) {
    long long int p;
    cin >> p;
    accum[i+1] = accum[i] + p;
  }
  
  long long int buf;
  buf = abs(accum[1] - (accum[n]-accum[1]));
  for (long long int i = 1; i < n; i++) {
    buf = buf < abs(accum[i] - (accum[n] - accum[i])) ? buf : abs(accum[i] - (accum[n] - accum[i]));
  }
  cout << buf << endl;
}
