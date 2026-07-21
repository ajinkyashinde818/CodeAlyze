#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
  ios_base::sync_with_stdio(false); 
  cin >> N;
  vector<int> v(N);
  long long x = 0LL, y = 0LL;
  for(int i=0; i<N; ++i){
     cin >> v[i];
       x += v[i];
  }
  long long res = INT_MAX;
  for(int i=N-1; i>=1; --i){
    y += v[i];
    x -= v[i];
    res = min(res, abs(x-y));
  }
  cout << res << "\n";
  return 0;
}
