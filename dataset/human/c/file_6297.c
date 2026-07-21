#include<stdio.h>

int main(void){
    
    int n,i,j,minv,maxv;
	
    scanf("%d",&n);
    
    int r[n];
	
    for(i=0; i<n; i++){ 
        scanf("%d",&r[i]);
        
    }
	
	minv=r[0];
	maxv = r[1]-r[0];
	for(j=1; j<n; j++){
	    (maxv > r[j]-minv) ? (maxv = maxv) : (maxv = r[j]-minv);
	    (minv < r[j]) ? (minv = minv) : (minv = r[j]);
	}
	
	printf("%d\n",maxv);
    
    return 0;
}
