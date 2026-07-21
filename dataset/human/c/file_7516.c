#include<stdio.h>
int main(){
	int i,x[10000],n;
	for(i=1;i<=10000;i++){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
	}
	
	n=i;
	
	for(i=1;i<n;i++){
		printf("Case %d: %d\n",i,x[i]);
	}	
	
	
	return 0;
}
