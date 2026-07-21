#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int n,i,a[100010],t;
  long s=0,amin=1e10;
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++){
    if (a[i]<0) t++;
    s+=abs(a[i]);
    if (amin > abs(a[i])) amin=abs(a[i]);
  }
  if (t%2) cout << s-amin*2 << endl;
  else cout << s << endl;
  return 0;
}
