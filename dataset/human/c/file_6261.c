#include<stdio.h>

int main(void){
	
	int n;
	
	scanf("%d", &n);
	
	int r[n], t;
	
	for(t=0; t<n; t++){
		scanf("%d", &r[t]);
	}
	
	int i, j, maxv=-999999999, minv=r[0];
	
	for(j=1; j<n; j++){
		
		if(maxv < r[j]-minv){
			maxv = r[j]-minv;
		}
		
		if(r[j] < minv){
			minv = r[j];
		}
	}
	
	
	/*for(i=0; i<n; i++){	
		
		if(max < max+r[i]){
			max=max+r[i];
		}
		
		if(max < r[i+1]-r[i]){
			max=r[i+1]-r[i];
		}	
	}*/
	
	
	printf("%d\n", maxv);
	return 0;
	
}
