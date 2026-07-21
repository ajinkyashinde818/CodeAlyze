#include<bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;

  vector<int> vec(N);
  long long sum = 0;
  for(int i = 0;i < N;i++) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }

  long long x = 0,y = sum,ans = 10000000000;
  for(int i = 0;i < N - 1;i++) {
    x += vec.at(i);
    y -= vec.at(i);
    ans = min(ans,abs(x - y));
  }

  cout << ans << endl;

}
