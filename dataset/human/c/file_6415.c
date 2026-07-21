#include<stdio.h>


int main(void){
	int n,i;
	int min,mp;
	int now;
	scanf("%d",&n);
	scanf("%d",&min);
	scanf("%d",&now);
	mp=now-min;
	if(min>now)min=now;
	
	for(i=2;i<n;i++){
		scanf("%d",&now);
		if(mp<now-min)mp=now-min;
		if(min>now)min=now;
	}
	printf("%d\n",mp);
	return 0;
}
