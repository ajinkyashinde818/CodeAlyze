#include<stdio.h>
int main(){
	int A_wh,B_wh,i,j,k,l,mas=0,ans=0;
	char mapA[50][50],mapB[50][50];
	
	scanf("%d %d ",&A_wh,&B_wh);
	
	for(i=0;i<A_wh;i++){
		for(j=0;j<=A_wh;j++){
			mapA[i][j]=getchar();
		}
	}
	
	for(i=0;i<B_wh;i++){
		for(j=0;j<=B_wh;j++){
			mapB[i][j]=getchar();
		}
	};
	for(k=0;k<A_wh;k++){
		for(l=0;l<A_wh;l++){
			for(i=0;i<B_wh;i++){
				for(j=0;j<B_wh;j++){
					if(mapA[k+i][l+j]!=mapB[i][j]){
						mas=0;
						break;
					}
					else{
						mas++;
					}
				}
			}
			if(mas==B_wh*B_wh){
				ans=1;
				break;
			}
		}
	}
	if(ans==1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}
