#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int k=2;
	while (k*(k-1)<2*n)
	{
		++k;
	}
	if (k*(k-1)!=2*n)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n"<<k<<endl;
	int s=k-1,ans[k][s],now=1;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			ans[i][j]=ans[j][i-1];
		}
		for (int j = i; j < s; ++j)
		{
			ans[i][j]=now;
			++now;
		}
	}
	for (int i = 0; i < k; ++i)
	{
		cout<<s;
		for (int j = 0; j < s; ++j)
		{
			cout<<" "<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
