#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc
const int N=1e5+5;
vector<int>ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	int k=1;
	while(k*(k-1)/2<n)++k;
	if(k*(k-1)/2!=n)
	{
		puts("No");
		exit(0);
	}
	int tot=0;
	rep(i,1,k)
	rep(j,i+1,k)
	{
		++tot;
		ans[i].push_back(tot);
		ans[j].push_back(tot);
	}
	puts("Yes");
	printf("%d\n",k);
	rep(i,1,k)
	{
		printf("%d ",int(ans[i].size()));
		for(auto x:ans[i])printf("%d ",x);
		puts("");
	}
}
