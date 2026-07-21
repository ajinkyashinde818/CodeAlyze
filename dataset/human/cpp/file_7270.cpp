#include <bits/stdc++.h>

using namespace std;
int a[200024];
long long sm[200024];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d",&a[0]);
	sm[0]=a[0];
	long long sum=a[0];
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
		sm[i]=sm[i-1]+a[i];
		sum+=a[i];
	}
	long long ans=abs(2*a[0]-sum);
	for(int i=1;i<n-1;i++){
			ans=min(abs(2*sm[i]-sum),ans);
	}
	printf("%lld\n",ans);
	return 0;
}
