#include<iostream>
using namespace std;
int main()
{
  int r,g,b,n,i,j;
  long long dem=0;
  cin >> r >> g >> b >> n;
  for (i=0; i<=n/r; i++)
    for (j=0; j<=(n-i*r)/g; j++)
        if ((n-i*r-j*g)%b==0) dem++;
  cout << dem;
  return 0;
}
