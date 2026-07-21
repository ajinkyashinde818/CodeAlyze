#include<stdio.h>

int check(char S[52][52],int h,int w){
	int i,j;

	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if((S[i][j]=='#')&&((S[i][j-1]=='.')&&(S[i][j+1]=='.')&&(S[i-1][j]=='.')&&(S[i+1][j]=='.'))){
				return 0;
			}
		}
	}
	return 1;
}

int main(void){
		char S[52][52]={0};
		int h,w,i,j;

		scanf("%d %d",&h,&w);

		for(i=1;i<=h;i++){
			scanf("%s",S[i]);
		}

		printf(check(S,h,w)?"Yes\n":"No\n");

		return 0;

}
