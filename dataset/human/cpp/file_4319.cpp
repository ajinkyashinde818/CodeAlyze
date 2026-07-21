#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)) f=ch=='-'?-1:f,ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int N=100005;

int a[N],b[N],a_[N],b_[N],fa[N],id[N];
map<int,int> lab;
int n,ans,sum,idx,cnt;

int getfather(int son){return fa[son]==son?son:fa[son]=getfather(fa[son]);}

void merge(int x,int y)
{
	x=getfather(x),y=getfather(y);
	if (x==y) return;
	fa[y]=x;
}

int main()
{
	//freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	n=read(),sum=0;
	for (int i=1;i<=n;++i) sum^=a[i]=read();
	a[n+1]=sum,sum=0;
	for (int i=1;i<=n;++i) sum^=b[i]=read();
	b[++n]=sum;
	copy(a,a+1+n,a_),copy(b,b+1+n,b_);
	sort(a_+1,a_+1+n),sort(b_+1,b_+1+n);
	for (int i=1;~ans&&i<=n;++i) if (a_[i]!=b_[i]) ans=-1;
	if (~ans)
	{
		idx=0;
		for (int i=1;i<=n;++i) lab[a_[i]]=idx+=a_[i]!=a_[i-1]||i==1;
		for (int i=1;i<=n;++i)
			if (a[i]!=b[i]||i==n)
			{
				ans+=i<n;
				if (!id[lab[a[i]]]) id[lab[a[i]]]=++cnt,fa[cnt]=cnt;
				if (!id[lab[b[i]]]) id[lab[b[i]]]=++cnt,fa[cnt]=cnt;
			}
		for (int i=1;i<=n;++i) if (a[i]!=b[i]) merge(id[lab[a[i]]],id[lab[b[i]]]);
		for (int i=1;i<=cnt;++i) ans+=i==getfather(i);
		--ans;
	}
	printf("%d\n",ans);
	//fclose(stdin),fclose(stdout);
	return 0;
}
