#include<stdio.h>
#define N 1000000
int main(void){
	int i,j,n;
	int R[N];
	int minv;
	int maxv=-1000000000;
	int price;
	scanf("%d",&n);
	
	for(i=0; i<n;i++){
		scanf("%d",&R[i]);
	}
	
	 minv=R[0];
	for(j=1;j<n;j++){
		if(R[j]-minv>maxv){maxv=R[j]-minv;}
		if(R[j]<minv){minv=R[j];}
	}
	price=maxv;
	
	
	printf("%d\n",price);
	
	return 0;
}
