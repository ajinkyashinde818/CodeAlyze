#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  int64_t sum = 0;
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  
  int64_t x = 0;
  int64_t ans = 10000000000;
  for(int i=0; i<N-1; i++){
    x += vec.at(i);
    sum -= vec.at(i);
    ans = min(ans,abs(x-sum));
  }
  cout << ans << endl;
}
