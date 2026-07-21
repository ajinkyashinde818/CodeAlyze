#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  	cin>>n;
  	vector<int>a(n);
  	long long ans=0;
  	int neg=0;
  	int flag=0;
  	for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]<0)neg++;
      if(a[i]==0)flag=1;
      a[i]=abs(a[i]);
    }
  	sort(a.begin(),a.end());
  	for(int i=0;i<n;i++)ans+=a[i];
  	if(!flag && neg%2==1)ans-=(2*a[0]);
  	cout<<ans<<endl;

  return 0;
  
}
