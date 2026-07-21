#include <stdio.h>

#define BUF (51)
int N,M;
char A[BUF][BUF],B[BUF][BUF];

void input(void){
	scanf("%d %d",&N,&M);
	int i=0;
	for(i=0;i<N;i++){
		scanf("%s",A[i]);
	}
	for(i=0;i<M;i++){
		scanf("%s",B[i]);
	}

}

int main(void){
	input();

	int ret = 0;

	int i,j,k;
	for(i=0;i<N-M+1;i++){
		for(j=0;j<N-M+1;j++){
			for(k=0;k<M*M;k++){
				if(B[k/M][k%M]!=A[k/M+i][k%M+j]){
					break;
				}

				if(k==M*M-1)ret = 1;		
			}

		}
	}

	if(ret) printf("Yes");
	else printf("No");
	return 0;
}
