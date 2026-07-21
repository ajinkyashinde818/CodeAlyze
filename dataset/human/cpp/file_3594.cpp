#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, i, countm = 0, ans = 0;
  cin >> N;
  
  vector<long> a(N);
  for(i = 0; i < N; i++){
    cin >> a.at(i);
  }
  
  for(i = 0; i < N; i++){
    if(a.at(i) < 0){
      countm++;
      a.at(i) = -a.at(i);
    }
  }
  
  if(countm % 2 == 0){
    for(i = 0; i < N; i++){
      ans += a.at(i);
    }
  }
  else{
    sort(a.begin(), a.end());
    ans = -a.at(0);
    for(i = 1; i < N; i++){
      ans += a.at(i);
    }
  }
  
  cout << ans << endl;
}
