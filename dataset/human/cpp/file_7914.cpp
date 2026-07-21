#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[2000000+10],ans=2100000000;
long long aa=0,bb=0,s;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    aa+=a[i];
  }
  for(int i=1;i<n;i++)
  {
    aa-=a[i];
	bb+=a[i];
	s=abs(aa-bb);
	if(s<ans)ans=s;
  }
  cout<<ans<<endl;
  return 0;
}
