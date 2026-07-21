#include <stdio.h>
#include <math.h>


int main() {
	int N,M, i,j,k,l,ans,p;
	char A[51][51],B[51][51];
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%s",A[i]);
	}
	for(i=0;i<M;i++){
		scanf("%s",B[i]);
	}
	ans = 0;
	for(i=0;i<N-M+1;i++){
		for(j=0;j<N-M+1;j++){
			p=1;
			/*A[i][j]から始めて、A[i+k][j+l]がB[k][l]と等しいか判定*/
			for(k=0;k<M;k++){
				for(l=0;l<M;l++){
					if(A[i+k][j+l]!=B[k][l]){
						p=0;
					}
				}
			}
			if(p==1){
				ans = 1;
			}
		}
	}
	if(ans == 0){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
}
