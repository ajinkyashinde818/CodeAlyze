#include <stdio.h>

int main(){
	int R;
	int G;
	int B;
	int N;
	scanf("%d",&R);
	scanf("%d",&G);
	scanf("%d",&B);
	scanf("%d",&N);
	int i;
	int j;
	int c;
	c=0;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
			if((N-i*R-j*G)%B==0&&N-i*R-j*G>=0){
				c=c+1;
			}
		}
	}
	printf("%d",c);
}
