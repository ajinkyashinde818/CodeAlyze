#include <stdio.h>

typedef long long ll;

ll YZ[10010];

int main(){

	int K,S;

	scanf("%d %d",&K,&S);

	int i,j;

	for(i=0;i<=K;i++){
		for(j=0;j<=K;j++){
			YZ[i+j]+=1ll;
		}
	}
	ll ans=0ll;
	for(i=0;i<=K;i++){
		if(S-i>=0){
		ans+=YZ[S-i];
		}
	}
	printf("%lld\n",ans);

	return 0;
}
