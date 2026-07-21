#include <stdio.h>
int main(void){
	int n,m,i,j,k,l,flag=0,exist=0;
	scanf("%d %d",&n,&m);
	char a[n][n],b[m][m];
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=0;i<m;i++)scanf("%s",b[i]);
	for(i=0;i<n;i++){//行
		for(j=0;j<n;j++){//列
			if(i+m-1>=n || j+m-1>=n) continue;
			flag=1;
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					if(b[k][l]!=a[i+k][j+l])flag=0;
				}
			}
			if(flag==1)exist=1;
		}
	}
	
	
	
	if(exist==1)	printf("Yes");
	else	printf("No");
	return 0;
}
