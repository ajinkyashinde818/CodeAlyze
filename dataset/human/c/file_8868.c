#include <stdio.h>
#include <math.h>

int main(void){
	int h,w;
	int i,j;
	int flag = 1;
	char s[52][52];
	scanf("%d %d",&h,&w);

	for(i = 0; i <= h+1;i++){
		for(j = 0;j <= w+1;j++){
			s[i][j] = '0';
		}
	}

	for(i = 1; i <= h;i++){
		for(j = 1;j <= w;j++){
			scanf(" %c",&s[i][j]);
		}
	}

	for(i = 1; i <= h;i++){
		for(j = 1;j <= w;j++){
			if(s[i][j] == '#'){
				if(s[i-1][j] != '#'&&s[i][j-1] != '#'&&s[i+1][j] != '#'&&s[i][j+1] != '#'){
					flag = 0;
				}
			}
		}
	}	

	if(flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}

	return 0;
}
