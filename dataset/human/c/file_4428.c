#include <stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	int D[N][2], i, flag=0;
	for (i=0; i<N; i++){
		scanf("%d %d", &D[i][0], &D[i][1]);
	}
	for (i=2; i<N; i++){
		if (D[i][0]==D[i][1] && D[i-1][0]==D[i-1][1] && D[i-2][0]==D[i-2][1]){
			flag=1;
			break;
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
