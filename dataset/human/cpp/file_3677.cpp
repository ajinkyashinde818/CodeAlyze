#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long>a(n);
  int mcnt=0;
  for(int i=0; i<n; i++){
    long aa;
    cin >> aa;
    a[i]=abs(aa);
    if(aa<0)mcnt++;
  }
  sort(a.rbegin(), a.rend());
  long ret=accumulate(a.begin(), a.end(), 0L);
  if(mcnt%2==1)ret-=2*a[n-1];
  cout << ret;
  return 0;
}
