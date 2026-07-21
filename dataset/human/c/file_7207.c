#include<stdio.h>

int main(){
	
	int n,m,i=0,j=0,k,a;
	int x[100]={},y[100]={};
	
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		x[i]=n;
		y[j]=m;
		i++;
		j++;
	}
	
	a=i;
	k=0;
	
	while(k<a){
		for(i=1;i<=x[k];i++){
			for(j=1;j<=y[k];j++){
				if((i+j)%2==0) printf("#");
				else if((i+j)%2==1) printf(".");
			}
			printf("\n");
		}
		k++;
		printf("\n");
	}
	
return 0;
}
