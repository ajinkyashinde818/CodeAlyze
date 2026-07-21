#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  int i = 0;
  int k = n % 2 ? (n + 1) / 2: n / 2;
  while (i++ < k - 1) cout << 0 << " ";
  while (i++ < n ) cout << m << " ";
  if (i != n - 1) cout << m << endl;

return 0;
}
