// 負の数の個数が偶数か、0が含まれていたらすべての要素を正の数にできるので
// 正の数の和を出力する?
// そうでない(0が含まれず、負の数の個数が奇数)時は
// 負の数の個数は1にできるので最も絶対値が小さい数を負の数、ほかを
// 正の数にして和をとればよい?
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n; cin >> n;
  int minus = 0, zero = 0;
  long long sum = 0;
  vector<long long> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
    if(v[i]==0) zero++;
    else if(v[i]<0) minus++;
    sum += abs(v[i]);
  }
  long long abs_min = abs(v[0]);
  for(int i=0;i<n;i++) abs_min = min(abs_min, abs(v[i]));
  
  if(minus % 2 == 0 || zero != 0){
    cout << sum << endl;
  }else{
    cout << sum - abs_min * 2;
  }
  
  return 0;
}
