#include<bits/stdc++.h>
using namespace std;
int s=200005,t,l,r,n,a[200005],b[200005];
int main()
{
	scanf("%d",&n);l=1,r=n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[n-i]);
	for(int i=1;i<=n;i++)
		if(a[i]==b[i])
		{
			if(s==200005) s=i;
			t=i;
		}
	for(int i=s;i<=t;i++)
		if(a[l]!=b[i]&&b[l]!=b[i]){swap(b[l],b[i]);l++;}
		else if(a[r]!=b[i]&&b[r]!=b[i]){swap(b[r],b[i]);r--;}
		else{puts("No");return 0;}
	puts("Yes");
	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	printf("\n");
	return 0;
}
