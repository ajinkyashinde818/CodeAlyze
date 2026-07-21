#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<long> data(N);
  long count = 0, ans = 0, minnum = 100000000000;
  for(int i = 0; i < N; i++){
    cin >> data.at(i);
    if(data.at(i) < 0){
      count++;
      data.at(i) *= -1;
    }
    ans += data.at(i);
    minnum = min(minnum, data.at(i));
  }
  if(count % 2 == 1)ans -= minnum * 2;
  cout << ans << endl;
  return 0;
}
