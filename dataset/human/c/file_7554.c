#include<stdio.h>


int main(void){

	int a,i=0,x[10001];
	do{
		i++;
		scanf("%d",&x[i]);
	}while(x[i]!=0);
	for(a=1;a<i+1;a++){
		if(x[a]==0){
			return 0;
		}else{
		printf("Case %d: %d\n",a,x[a]);
		}
	}

}
