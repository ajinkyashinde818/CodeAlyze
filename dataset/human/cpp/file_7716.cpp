#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  long long sum = 0;
  long long sunuke = 0;
  long long nmin = LLONG_MAX;
 
  vector<int> a(N);
  
  for(int i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
  }
  
  for(int i = 0; i < N - 1; i++){
    sunuke += a[i];
    nmin = min(nmin, abs(sum - (2*sunuke)));
  }
  
  cout << nmin << endl;
  
  return 0;
}
