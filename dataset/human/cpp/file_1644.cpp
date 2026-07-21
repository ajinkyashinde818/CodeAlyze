#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
main()
{
	cin>>n;
	int k=1;
	for(;k*(k-1)<n*2;k++);
	if(k*(k-1)!=n*2)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl<<k<<endl;
	vector<vector<int> >ans(k);
	int p=0,q=1;
	for(int i=1;i<=n;i++)
	{
		ans[p].push_back(i);
		ans[q].push_back(i);
		q++;
		if(q>=k)p++,q=p+1;
	}
	for(int i=0;i<k;i++)
	{
		cout<<k-1;
		for(int j=0;j<k-1;j++)cout<<" "<<ans[i][j];
		cout<<endl;
	}
}
