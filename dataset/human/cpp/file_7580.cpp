#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 200000;
int main()
{
  int n,i;
  long long a,res=2e15;
  long long s[N_MAX];
  cin >> n >> a;
  s[0]=a;
  for(i=1;i<n;i++){
    cin >> a;
    s[i]=s[i-1]+a;
  }
  for(i=0;i<n-1;i++)
    res=min(res,abs(s[n-1]-2*s[i]));
  cout << res << endl;
  return 0;
}
