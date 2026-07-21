#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  long long X=0, su_sum=0, ans = 1000000000000000000LL;
  cin >> N;
  vector<long long> a(N);

  //入力を受け取る＋カードの総和Xの計算
  for (int i=0; i<N; i++){
    cin >> a[i];
    X += a[i];
  }

  //su_sum(xのこと)をi=0 ~ Nまで計算し、ansより小さければ更新
  for (int i=0; i<N-1; i++){
    su_sum += a[i];
    ans = min(ans, abs(X - 2*su_sum));
  }

  cout << ans << endl;

  return 0;
}
