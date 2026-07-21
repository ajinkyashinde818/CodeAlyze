#include<stdio.h>

#define mod 1000000007

int main(){
	int n,i,j;
	char s[100000];
	long long ko[2][27]={0};
	long long ans=0;
	scanf("%d%s",&n,s);
	for(i=n-1;i>=0;i--){
		long long tmp=1;
		for(j=0;j<27;j++)ko[i%2][j]=0;
		ko[i%2][s[i]-'a']++;
		for(j=0;j<27;j++){
			ko[i%2][j]+=ko[(i+1)%2][j];
			if(s[i]-j!='a')tmp*=ko[i%2][j]+1;
			tmp=tmp%mod;
		}
		ans+=tmp;
		ans=ans%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
