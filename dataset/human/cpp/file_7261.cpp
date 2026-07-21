#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  int64_t sum = 0, leftSide = 0, dif = int64_t(pow(10, 16));
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) {
    
    int64_t a; cin >> a;
    
    vec[i] = a; sum += a;
    
  }
  
  for (int i = 0; i < N - 1; i++) {
    
    leftSide += vec[i];
    
    int64_t rightSide = sum - leftSide;
    
    int64_t tmpDif = abs(leftSide - rightSide);
    
    dif = min(dif, tmpDif);
    
  }
  
  cout << dif << endl;
  
}
