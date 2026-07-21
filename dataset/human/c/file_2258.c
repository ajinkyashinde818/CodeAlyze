#include <stdio.h>
#include <string.h>

int map[1000][1000];

int mini(int a,int b,int c){
	int tmp = (a > b) ? b : a;
	return (tmp > c) ? c : tmp;
}

int main(){
	int i,j,n,min,max;
	char str[1024];

	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		memset(map,0,sizeof(map));
		for(i = 0;i < n;i++){
			scanf("%s",str);
			for(j = 0;j < n;j++){
				if(str[j] == '.'){
					map[i][j] = -1;
				}else{
					map[i][j] = 0;
				}
			}
		}

		max = 0;

		for(i = 0;i < n;i++){
			if(map[0][i] == -1){
				map[0][i] = 1;
				max = 1;
			}
			if(map[i][0] == -1){
				map[i][0] = 1;
				max = 1;
			}
		}

		for(i = 1;i < n;i++){
			for(j = 1;j < n;j++){
				if(map[i][j] == -1){
					min = mini(map[i-1][j-1],map[i][j-1],map[i-1][j]);
					map[i][j] = min+1;
					if(max < (min+1)){
						max = (min+1);
					}
				}
			}
		}

		printf("%d\n",max);
	}

	return 0;
}
