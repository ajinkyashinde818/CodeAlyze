#include<stdio.h>
int main(){
	int n,m,i,j,k,l;
	char a[60][60],b[60][60];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%s",b[i]);
	}
	int flag=0;
	for(i=0;i<=n-m;i++){
		for(j=0;j<=n-m;j++){
			flag=0;
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l])flag=1;
				}
			}
			if(flag==0){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
