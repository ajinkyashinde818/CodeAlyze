#include<stdio.h>


int large(int a, int b){
	
	int p;
	
	if(a>b){
		p = a;
	}else{
		p = b;
	}
	
	return (p);
}

int small(int a, int b){
	
	int p;
		
		if(a<b){
			p = a;
		}else{
			p = b;
		}
	
	return (p);
}

int main (void){
	
	int n,minv=0,maxv=-1000000001,i;
	int r[200001]={0};
	scanf("%d",&n);
	
	scanf("%d",&r[0]);
	minv = r[0];
	for(i=1;i<n;i++){
		scanf("%d",&r[i]);
		
		maxv =large(maxv,r[i]-minv);
		minv =small(minv,r[i]);
	}
	
		printf("%d\n",maxv);
	
return 0;
}
