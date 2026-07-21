#include <stdio.h>

int main(void) {
	unsigned long prm[10000]={2,3};
	int i,j,cnt=2,judge;
	for(i=5;cnt<10000;i+=2) {
		judge=1;
		for(j=0;prm[j]*prm[j]<=i;j++) {
			if(!(i%prm[j])) {
				judge=0;
				break;
			}
		}
		if(judge) {
			prm[cnt++]=i;
		}
	}
	unsigned long long ans;
	while(scanf("%d",&i),i) {
		ans=0;
		for(j=0;j<i;ans+=prm[j++]){}
		printf("%lld\n",ans);
	}
	return 0;
}
