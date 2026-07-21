#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b > a) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int n; cin >> n;
  
  long long int ans = 0;
  int minus = 0;
  int minimum = 2e9;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    int temp; cin >> temp;
    if (temp < 0) {minus++; temp *= -1;}
    minimum = min(minimum, temp);
    ans += temp;
  }
  
  if (minus % 2 == 1) ans -= 2 * minimum;
  
  cout << ans << endl;
  
}
