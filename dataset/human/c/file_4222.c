#include <stdio.h>
#define MOD 1000000007
int main(void){
	int n,m,i;
	scanf("%d %d", &n,&m);
	long long escada[n+1];
	for(i=0;i<=n;i++)escada[i]=1;
	int quebr[m];
	for(i=0;i<m;i++)scanf("%d",&quebr[i]);
    for(i=0;i<m;i++)escada[quebr[i]]=0;
	for(i=2;i<=n;i++){
		if(escada[i]!=0){
			escada[i]=(escada[i-2]+escada[i-1])%MOD;
		}
	}
	printf("%lld\n",escada[n]);
	return 0;
}
