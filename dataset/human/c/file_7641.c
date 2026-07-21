#include<stdio.h>
int main(){

	int data[10000],i=0,maxix;
	while(i<=10000){
		scanf("%d",&data[i]);
		if(data[i]==0){
			maxix=i-1;
			break;
		}
		i++;
	}
	i=0;
	while(i<=maxix){
		printf("Case %d: %d\n",i+1,data[i]);
		i++;
	}
	return 0;
}
