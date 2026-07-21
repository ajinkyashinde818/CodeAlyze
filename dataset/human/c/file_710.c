#include<stdio.h>

int main(void){
	int n,m,i,j,k,l,f = 0;
	char a[64][64],b[64][64];
	scanf("%d%d",&n,&m);
	for(i = 0;i < n;i++){scanf("%s",a[i]);}
	for(i = 0;i < m;i++){scanf("%s",b[i]);}
	for(i = 0;i <= n-m;i++){
		for(j = 0;j <= n-m;j++){
			for(k = 0;k < m;k++){
				for(l = 0;l < m;l++){
					if(a[i+k][j+l] != b[k][l]){f = -1;break;}
					if(k == m-1 && l == m-1){printf("Yes\n");return 0;}
				}
				if(f == -1){break;}
			}
			if(f == -1){f = 0;}
		}
	}
	printf("No\n");
	return 0;
}
