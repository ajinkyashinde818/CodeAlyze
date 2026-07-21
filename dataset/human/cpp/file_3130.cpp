#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  int count = 0;
  
  for(int i = 0; i < n; i++){
    if(a.at(i) < 0){
      count++;
      a.at(i) = - a.at(i);
    }
  }
  
  sort(a.begin(), a.end());
  long long ans = 0;
  
  if(count % 2 == 0){
    for(int i = 0; i < n; i++){
      ans += a.at(i);
    }
    cout << ans << endl;
  }
  else{
    a.at(0) = -a.at(0);
    for(int i = 0; i < n; i++){
      ans += a.at(i);
    }
    cout << ans << endl;
  }
}
