#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a.at(i);
    a.at(i) += a.at(i-1);
  }
  
  long long dif = pow(10, 18);
  for(int i = 1; i < n; i++){
    dif = min(dif, abs(a.at(i) - a.at(n) + a.at(i)));
  }
  
  cout << dif << endl;
}
