#include <stdio.h>
#define MAXNUM 10000

int main(){
	int i,temp=1;
	int dataset[MAXNUM];
	for(i=0;i<MAXNUM;i++){
		dataset[i]=0;
	}
	
	i=0;
	while(temp!=0){
		scanf("%d\n",&temp);
	    dataset[i]=temp;
	    i++;
	}
	
	i=0;
	while(1){
		if(dataset[i]==0){
			break;
		}else{
			printf("Case %d: %d\n",i+1,dataset[i]);
			i++;
		}
	}
	
	
	return 0;
}
