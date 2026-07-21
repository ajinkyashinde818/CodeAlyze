#include<stdio.h>

int main (void){
	
	int x,n[10000];
	int i,j;
	for(i=0;i<10000;i++){
		scanf("%d",&x);
		n[i]=x;
		if(n[i]==0){
			break;
		}
	}
	
	for(j=1;j<=i;j++){
		printf("Case %d: %d\n",j,n[j-1]);
	}
	return 0;
}
