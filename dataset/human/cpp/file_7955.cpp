#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n, temp;
  cin >> n;
  int a[n];
  long long sum = 0;  
  for(int i = 0; i < n; i++){
    cin >> temp;
    sum += temp;
    a[i] = temp;
  }
  long long su, ara;
  long long ans = 100000000000000;
  su = 0;
  ara = sum;
  for(int i = 0; i < n - 1; i++){
    su += a[i];
    ara = sum - su;
    ans = min(ans, abs(su - ara));
  }
  cout << ans << endl;
  return 0;
}
