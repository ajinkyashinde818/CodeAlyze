#include <stdio.h>

int main(void) {
	int K,S;
	int i,j,cnt=0;
	scanf("%d %d",&K,&S);
	for(i=0;i<=K;i++){
		for(j=0;j<=K;j++){
			if((S-i-j)>=0&&(S-i-j)<=K){
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
