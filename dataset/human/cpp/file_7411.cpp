#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  
  long long sum = 0;
  for(int i = 0; i < N; i++){
  	sum += a[i];
    if(i == 0)continue;
    a[i] += a[i - 1];
  }
  
  long long ans = LLONG_MAX;
  for(int i = 0; i < N - 1; i++){
  	ans = min(ans, abs(a[i] - (sum - a[i])));
  }
  
  cout << ans << endl;
  return 0;
}
