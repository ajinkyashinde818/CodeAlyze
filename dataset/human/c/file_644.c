#include<stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
	int n,m,find;
	char a[50][50],b[50][50];

	scanf("%d %d",&n,&m);
	FOR(i,0,n) scanf("%s",a[i]);
	FOR(i,0,m) scanf("%s",b[i]);

	FOR(i,0,n-m+1){
		FOR(j,0,n-m+1){
			find = 1;
			FOR(k,0,m){
				FOR(l,0,m){
					if(a[i-k][j-l] != b[k][l]) find = 0;
				}
			}
			if(find == 1){
				printf("Yes\n");
				return 0;
			}
		}
	}

	printf("No\n");
}
