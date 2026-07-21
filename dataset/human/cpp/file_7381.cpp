#include<bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001;
int main(){
  int n;
  cin >> n;
  vector<long long> acc(n + 1);
  acc[0] = 0;
  long long temp;
  for(int i = 0; i < n; ++i){
    cin >> temp;
    acc[i + 1] += temp + acc[i];
  }
  long long ans = INF;
  for(int i = 1; i < n; ++i){
    ans = min(ans, abs((acc[n] - acc[i]) - acc[i]));
  }
  cout << ans << endl;
}
