#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	long long n,ans=0,total,j,i;
	scanf("%lld",&n);
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			total=0,j=1;
			while(n%i==0){
				n/=i;
				total++;
			}
			while(total-j>=0){
				total-=j;
				j++;ans++;
			}
		}
	}
	if(n!=1)ans++;
	printf("%lld\n",ans);
}
