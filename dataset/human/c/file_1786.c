#include<stdio.h>

int main(){
		int n,i;
		long long a[21],b[21],c[21],ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lld",&a[i]),a[i]--;
		for(i=0;i<n;i++)scanf("%lld",&b[i]);
		for(i=0;i<n-1;i++)scanf("%lld",&c[i]);
		ans=b[a[0]];
		for(i=1;i<n;i++){
				ans+=b[a[i]];
				if(a[i]==a[i-1]+1)ans+=c[a[i-1]];
		}
		printf("%lld\n",ans);
		return 0;
}
