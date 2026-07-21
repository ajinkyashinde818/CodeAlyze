#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int N,zoro;
	scanf("%d",&N);
	int D[N][N];
	for (int i;i<N;i++){
		scanf("%d %d",&D[i][0],&D[i][1]);
		if (D[i][0]==D[i][1]){
			zoro++;
		} else zoro=0;
		if (zoro==3){
			printf("%s","Yes");
			exit(0);
		}
	}
	printf("%s","No");
	return 0;
}
