#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100005,M=1000;
typedef long long ll;
ll a[N],res=0;
int ans[M][M],cnt[M];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >>n;
	int tmp=sqrt(2*n);
	if(tmp*(tmp+1)!=2*n)
	{
		cout <<"No"<<endl;
		return 0;
	}
	else cout <<"Yes"<<endl;
	int k=tmp+1;
	cout <<k<<endl;
	int tmp1=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			ans[i][++cnt[i]]=++tmp1;
			ans[j][++cnt[j]]=tmp1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cout <<cnt[i];
		for(int j=1;j<=cnt[i];j++)cout <<' '<<ans[i][j];
		cout <<endl;
	}
	return 0;
}
