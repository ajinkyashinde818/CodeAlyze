#include<stdio.h>

int main() {
	int i,j,a[10000];
	for(i=1;i<=10000;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			break;
		}
	}	
	for(j=1;j<i;j++){
		printf("Case %d: %d\n",j,a[j]);
		if(a[j]==0){
			break;
		}
	}
	return 0;
}
