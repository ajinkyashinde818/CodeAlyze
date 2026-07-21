#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> a(N);
  for_each(a.begin(), a.end(),
           [](auto &v){cin >> v;});

  long long all_sum = 0;
  for_each(a.begin(), a.end(),
           [&](auto v){all_sum += v;});

  long long partial_sum = 0;
  long long ans = 1e16;
  for(int i = 0; i < N - 1; i++){
    partial_sum += a[i];
    ans = min(ans, abs((all_sum - partial_sum) - partial_sum));
  }

  cout << ans << endl;
}
