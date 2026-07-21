#include<stdio.h>

long long sums[1000000];

int main(){
		int n,i,k,j,c=0;
		long long ans,x,a[1000];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		for(i=0;i<n;i++){
				for(j=i;j<n;j++){
						if(j>i)sums[c]=sums[c-1]+a[j];
						else sums[c]=a[j];
						c++;
				}
		}
		int t;
		x=0;
		long long ki=1;
		for(i=0;i<40;i++)ki*=2;
		for(t=0;t<41;t++){
						int co=0;
						for(i=0;i<c;i++){
								if(((x+ki)&sums[i])==(x+ki))co++;
						}
						if(co>=k)x+=ki;
				ki/=2;
		}
		printf("%lld\n",x);
		return 0;
}
