#include<stdio.h>

int main(){
	int d[100][2],n,num = 0,i,j;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		for(j = 0;  j < 2; j++){
			scanf("%d",&d[i][j]);
			if(i > 1 &&j == 1){
				if(d[i - 2][0] == d[i - 2][1] && d[i - 1][0]== d[i - 1][1] && d[i][0] == d[i][1]){
					num = 1;
				}
			}
		}
	}
	if(num == 0){
		printf("No");
	}
	else{
		printf("Yes");
	}
}
