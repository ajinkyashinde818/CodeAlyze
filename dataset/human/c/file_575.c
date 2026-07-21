#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char imgN[n][n];
	char imgM[m][m];
	int i,j;
	char s[100];
	for(i=0;i<n;i++){
		scanf("%s",s);
		strcpy(imgN[i],s);
	}
	for(i=0;i<m;i++){
		scanf("%s",s);
		strcpy(imgM[i],s);
	}
	
	//n>=m
	int k,l;
	
	int existMinN;
	for(i=0;i<=n-m;i++){
		for(j=0;j<=n-m;j++){
			existMinN=1;
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					if(imgM[k][l]!=imgN[k+i][l+j]){
						existMinN=0;
						break;
					}
				}
				if(existMinN==0){
					break;
				}
			}
			if(existMinN==1){
				break;
			}
		}
		if(existMinN==1){
			//printf("i:%d j:%d\n",i,j);
			break;
		}
	}
	
	if(existMinN){
		puts("Yes");
	}else{
		puts("No");
	}
	
    return 0;
}
