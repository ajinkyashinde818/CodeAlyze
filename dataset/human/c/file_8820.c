#include <stdio.h>
int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	char s[51][51];
	int i,j;
	for(i=0;i<h;i++){
			scanf("%s",&s[i]);
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){	
			if(s[i][j]=='#'){
				if(s[i-1][j]=='.'&&s[i][j-1]=='.'&&s[i][j+1]=='.'&&s[i+1][j]=='.'){
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
	}
