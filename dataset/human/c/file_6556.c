#include<stdio.h>
int R[200000];

int main(){
	int n,i,temp;
	int minnum,maxsub;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);
	}
	
	minnum = R[0];
	maxsub = R[1]-minnum;
	if(minnum > R[1])minnum = R[1];
	for(i=2;i<n;i++){
		if(R[i] - minnum > maxsub )maxsub = R[i] - minnum;
		if(minnum > R[i])minnum = R[i];
	}
	
	printf("%d\n",maxsub);
	
	return 0;
}
