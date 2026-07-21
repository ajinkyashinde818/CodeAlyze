#include <stdio.h>

int A[105];

int main() {

	int N,D,X;

	scanf("%d",&N);
	scanf("%d %d",&D,&X);

	int i,j;

	for(i=0;i<N;i++){
	scanf("%d",&A[i]);
	}

	int ans=X;

	for(i=0;i<N;i++){
		for(j=1;j<=D;j+=A[i]){
		ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
