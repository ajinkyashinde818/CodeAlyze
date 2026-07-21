#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,L,R,a[maxn],b[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	reverse(b+1,b+1+n);
	for (int i=1;i<=n;i++)
		if (a[i]==b[i])
		{
			if (!L) L=i;
			R=i;
		}
	if (L)
	{
		int head=1,x=a[L];
		bool sol=true;
		for (int i=L;i<=R;i++)
		{
			while (head<=n && (a[head]==x || b[head]==x)) head++;
			if (head>n)
			{
				sol=false;
				break;
			}
			swap(b[head++],b[i]);
		}
		if (!sol)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i=1;i<n;i++) printf("%d ",b[i]);
	printf("%d\n",b[n]);
	return 0;
}
