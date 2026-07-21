#include<stdio.h>

int main(){
	
	int H,W,i,j,a[55][55]={0};
	char s[55][55];
	
	scanf("%d %d",&H,&W);
	
	for(i=1;i<=H;i++){
		scanf("%s",s[i]);
	}
	
	for(i=1;i<=H;i++){
		for(j=0;j<W;j++){
			if(s[i][j]=='#'){
				a[i][j+1]++;
			}
		}
	}
	
	
	
	for(i=1;i<=H;i++){
		for(j=1;j<=W;j++){
			if(a[i][j]==1){
				if(a[i-1][j]+a[i][j-1]+a[i][j+1]+a[i+1][j]==0){
					printf("\nNo\n");
					return 0;
				}
			}
		}
	}
	printf("\nYes\n");
	
	return 0;
}
