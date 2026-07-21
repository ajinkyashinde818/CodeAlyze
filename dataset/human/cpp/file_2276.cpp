#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,s;
  cin >> n;
  s = 0;
  long long x =0;
  vector<int> a(n),b(n);
  for(int i = 0 ; i < n ; i++){
    cin >> a.at(i);
    if(a.at(i) < 0){
      b.at(i) = -a.at(i);
      s++;
    }
    else {
      b.at(i) = a.at(i);
    }
  }
  
  sort(b.begin(), b.end());
  for(int i = 0 ; i<n ; i++){
    x += b.at(i);
  }
    
  if(s%2 == 0){
    cout << x << endl;
  }
  else {
    cout << x -2*b.at(0) << endl;
  }
}
