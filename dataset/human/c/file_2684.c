#include<stdio.h>

int main(void){
	int K,S;
	int x,y,z;
	int count = 0;

	scanf("%d %d",&K,&S);

	for(x=0;x<=K;x++){
		for(y=0;y<=K;y++){
			int z = S-x-y;
			if(0 <= z && z <= K){
				count++;
			}
		}
	}

	printf("%d\n",count);

return 0;
}
