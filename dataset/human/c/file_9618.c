#include <stdio.h>

int checkHit(char have[], char hit[]){
	int i;
	for(i = 0; i < 9; i++){
		if(hit[i] != '*' && hit[i] != have[i]){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int n,m,i,j;
	int money;
	char hitnum[100][9];
	int g[100];
	char havenum[9];
	while(1){
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0){break;}
		money = 0;
		for(i = 0; i < n; i++){
			scanf("%s%d",hitnum[i],&g[i]);
		}
		for(i = 0; i < m; i++){
			scanf("%s",havenum);
			for(j = 0; j < n; j++){
				if(checkHit(havenum,hitnum[j])){
					money += g[j];	
					break;
				}
			}
		}
		printf("%d\n",money);
	}

	return 0;
}
