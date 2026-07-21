#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, r;
  cin >> n >> r;
  (n >= 10) ? cout << r << "\n" : cout << r + 100*(10 - n) << "\n";
return 0;
}
