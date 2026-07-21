#include <stdio.h>

int main(void){
	int K,S;
	scanf("%d",&K);
	scanf("%d",&S);
	int c = 0;
	for(int x=0;x<=K;x++){
		if(x>S) break;
		for(int y=0;y<=K;y++){
			if(S-x-y>=0 && S-x-y<=K) c++;
		}
	}
	printf("%d\n",c);
	
	return 0;
}
