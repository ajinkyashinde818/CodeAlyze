#include<stdio.h>

int main(){
		int n,m,i,j;
		char a[50][51],b[50][51];
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)scanf("%s",a[i]);
		for(i=0;i<m;i++)scanf("%s",b[i]);
		for(i=0;i<=n-m;i++){
				for(j=0;j<=n-m;j++){
						int k,l,f=0;
						for(k=0;k<m;k++){
								for(l=0;l<m;l++){
										if(a[i+k][j+l]!=b[k][l]){
												f=1;
												break;
										}
								}
								if(f==1)break;
						}
						if(f==0){
								puts("Yes");
								return 0;
						}
				}
		}
		puts("No");
		return 0;
}
