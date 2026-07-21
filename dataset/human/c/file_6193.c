#include<stdio.h>

int main(){

	int n;
	scanf("%d",&n);
	int i,R[200010];
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);	
	}
	int maxv,minv,j;
	maxv=R[1]-R[0];
	minv = R[0];
	for(j=1;j<n;j++){
		if(R[j]<minv){minv=R[j];}
		else if(R[j]-minv>maxv){maxv=R[j]-minv;}
	}
	printf("%d\n",maxv);
	return 0;
}
