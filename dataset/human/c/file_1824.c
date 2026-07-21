#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int a[100],b[100],c[100],n;
	int ans=0,tmp=0,tmp2=0;

	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		tmp = a[i];
		if(a[i]!=a[i-1]+1){
			ans += b[tmp];
		}else{
			ans += b[tmp] + c[tmp-1];
		}
	}		
	printf("%d\n", ans);
}
