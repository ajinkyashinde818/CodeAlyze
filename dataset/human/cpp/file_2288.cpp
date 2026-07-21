#include<iostream>
#include <algorithm>
using namespace std;
int N_MAX=100000;
int main()
{
  int n,i;
  int a[N_MAX];
  long long res=0;
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  sort(a,a+n);
  for(i=0;i<n-1;i+=2)
    res+=max(-a[i]-a[i+1],a[i]+a[i+1]);
  if(i<n) res+=a[n-1];
  cout << res << endl;
  return 0;
}
