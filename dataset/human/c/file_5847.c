#include<stdio.h>

int main(){
	int max,min,sa=0,i,n,r[200000]={};
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&r[i]);
	min = r[0];
	max=min;	
	for(i=0;i<n-1;i++){
		if(r[i+1]-min<0) {
			min = r[i+1];
			max = min;
		}
		if(max<r[i+1]) max = r[i+1];
		if(sa<max-min) sa=max-min;
	}

	if(max==min&&sa==0){
		sa = r[1]-r[0];
		for(i=0;i<n-1;i++){
			if(sa<r[i+1]-r[i]) sa = r[i+1]-r[i]; 
		}	
	}

	printf("%d\n",sa);

	return 0;
}
