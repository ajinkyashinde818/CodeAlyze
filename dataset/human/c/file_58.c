#include <stdio.h>

int main(void){
	int R,G,B,N;
	int count=0;
	scanf("%d %d %d %d",&R,&G,&B,&N);

	for(int r=0; r*R<=N; r++){
		for(int g=0; r*R+g*G<=N; g++){
			if((N-r*R-g*G) % B==0){ count++;}
		}
	}
	printf("%d\n",count );
}
