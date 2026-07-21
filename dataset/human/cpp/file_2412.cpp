#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int flag = 0;
  int count = 0;
  long long res = 1000000000;
  long long ans = 0;
  long long cur = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> cur;
    if(cur < 0){
      count++;
      cur = cur*-1;
      ans += cur;
    }
    else if(cur == 0){
      flag = 1;
    }
    else{
      ans += cur;
    }
    res = min(res,cur);
  }
  if (count%2 == 1 and flag == 0){
    cout << ans-res*2 << endl;
  }
  else{
    cout << ans << endl;
  }
}
