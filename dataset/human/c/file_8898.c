#include<stdio.h>
char s[50][50];
int i,j;
int f(int a,int b){
	return s[i][j]==s[a][b];
}
int main(void){
	int h,w,num;
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(s[i][j]=='#'){
				num=f(i-1,j)+f(i+1,j)+f(i,j-1)+f(i,j+1);
				if(!num){
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
}
