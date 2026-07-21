#include<stdio.h>

int main(){
	int N, D[111][2];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d%d", &D[i][0], &D[i][1]);
		if(i > 1){
			if(D[i][0] == D[i][1] && D[i-1][0] == D[i-1][1] && D[i-2][0] == D[i-2][1]){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
