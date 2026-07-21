#include<iostream>
using namespace std;
int main()
{
  int r,g,b,n,i,j,m,res=0;
  cin >> r >> g >> b >> n;
  for(i=0;i<=n/r;i++){
    m=n-i*r;
    for(j=0;j<=m/g;j++)
      if((m-j*g)%b==0) res++;
  }   
  cout << res << endl;
  return 0;
}
