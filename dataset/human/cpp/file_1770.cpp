#include<iostream>
using namespace std;
int n,m,a[1<<17],used[1<<18];
main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=m;i--;)
	{
		if(!used[a[i]])
		{
			cout<<a[i]<<endl;
			used[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++)if(!used[i])cout<<i<<endl;
}
