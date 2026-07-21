#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 200005;
typedef long long ll;
int main(){
  int N; cin >> N;
  ll a[MAX_N];
  ll x;
  ll y;
  for(int i=0;i<N;i++){
    cin >> a[i];
    if(i>0){
      y += a[i];
    }
  }
  x = a[0];
  ll ans = abs(x - y);
  ll temp;
  for(int i=1; i<N-1;i++){
    x = x + a[i];
    y = y - a[i];
    temp = abs(x-y);
    if(temp < ans){
      ans = temp;
    }
  }
  cout << ans << endl;

  return 0;
}
