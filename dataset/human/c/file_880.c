#include<stdio.h>
int main(){
	long long n;
	scanf("%lld\n",&n);
	int ans=0;
	for(long long i=2;i*i<=n;i++)if(n%i==0){
		int cnt=0;
		while(n%i==0)n/=i,cnt++;
		for(int j=1;j<=cnt;j++){
			cnt-=j;
			ans++;
		}
	}
	if(n!=1)ans++;
	printf("%d\n",ans);
}
