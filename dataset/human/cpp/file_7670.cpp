#include <stdio.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <cstdlib>

int main(void){
  int n,a[200000];
  long long afor[200000],abak[200000];
  cin >> n;
  for(int i = 0;i < n;++i)
    cin >> a[i];

  afor[0] = a[0];
  for(int i = 1;i < n-1;++i)
    afor[i] = a[i] + afor[i-1];

  abak[0] = afor[n-2] -a[0] +a[n-1];
  for(int i = 1;i < n-1;++i)
    abak[i] = abak[i-1] - a[i];

  long long min = INT_MIN;
  long long ans = INT_MAX;
  for(int i = 0;i < n-1;++i){
    min = abs(afor[i] - abak[i]);
    if(min < ans)
      ans = min;
  }
  cout << ans << endl;
}
