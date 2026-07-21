#include<stdio.h>
#include<math.h>

int main(void){
    int i=0,n,j,x,minv,maxv;
	
	scanf("%d",&n);
	
	int R[n];
	
	while((scanf("%d",&x)!=EOF)){
		R[i]=x;
		i++;
	}
	
	minv=R[0];
	maxv=R[1]-R[0];
	
	for(j=1;j<n;j++){
		
		if(maxv<R[j]-minv){
			maxv=R[j]-minv;
		}
		if(minv>R[j]){
			minv=R[j];
		}
	}
	
	printf("%d\n",maxv);
	
    return 0;
}
