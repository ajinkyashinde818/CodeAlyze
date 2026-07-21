#include<bits/stdc++.h>

using namespace std;

int n,xb,a[1200][1200];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n+1;++i)
		if (i*(i-1)/2==n){
			printf("Yes\n%d\n",i);
			for (int j=1;j<=i;++j){
				printf("%d",i-1);
				for (int k=1;k<=i;++k){
					if (k<j) a[j][k]=a[k][j];
					if (k>j) a[j][k]=++xb;
					if (k!=j) printf(" %d",a[j][k]);
				}
				puts("");
			}
			return 0;
		}
	puts("No");
	
	return 0;
}
