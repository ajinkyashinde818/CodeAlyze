#include<stdio.h>

char a[50][51],b[50][51];


int main(int argc, char const *argv[]) {
	int n,m,i,j,k,l,f;
	char c;
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%s",b[i]);
	}
	for(i=0;i<=n-m;i++){
		for(j=0;j<=n-m;j++){
			f=1;
			for(k=i;k<i+m;k++){
				for(l=j;l<j+m;l++){
					if(a[k][l]!=b[k-i][l-j]) f=0;
				}
			}
			if(f){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
