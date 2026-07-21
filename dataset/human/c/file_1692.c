#include <stdio.h>

int main(void){
	int N;
	scanf("%d",&N);
	int Ai[N];
	int Bi[N];
	int Ci[N-1];
	int i,sum = 0;

	for(i = 0 ;i < N; i++){
		scanf("%d",&Ai[i]);
	}
	for(i = 0 ;i < N; i++){
		scanf("%d",&Bi[i]);
	}
	for(i = 0 ;i < N-1; i++){
		scanf("%d",&Ci[i]);
	}
	for(i = 0; i < N; i++){
		if(Ai[i+1] != Ai[i] + 1){
			sum += Bi[Ai[i]-1];
		}
		else if(Ai[i+1] == Ai[i] + 1){
			sum += (Bi[Ai[i]-1] + Ci[Ai[i]-1]);
		}
	}
	printf("%d",sum);
	return 0;
}
