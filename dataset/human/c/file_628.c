#include <stdio.h>
#include <string.h>
int main(void){
	int n,m,i,j,k,l;
	char a[50][51],b[50][51];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%s",b[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l]){
						goto LOOP_END;
					}
				}
			}
			LOOP_END:
			if(k==m&&l==m){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
