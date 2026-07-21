#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int count=0;
  int count_zero=0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i] < 0) count++;
    else if(a[i] == 0) count_zero++;
  }
  sort(a, a+n);
  long long ans=0;
  if(count_zero>0){
    for(int i=0; i<count; i++){
      ans -= a[i];
    }
    for(int i=count; i<n; i++) ans += a[i];
  }
  else{
    if(count%2 == 1){
      for(int i=0; i<count-1; i++) ans -= a[i];
      for(int i=count-1; i<n; i++) ans += a[i];
      if(count<n) ans = max(ans, ans-2*a[count-1]-2*a[count]);
    }
    else{
      for(int i=0; i<count; i++) ans -= a[i];
      for(int i=count; i<n; i++) ans += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
