#include <stdio.h>
#define N 200000


int n, j,maxv,minv;
int R[N];
int main(void)
{
	
	
	scanf("%d",&n);
	
	
	for(j = 0; j < n; j++){
	   
	   scanf("%d",&R[j]);
	
	}
	maxv = R[1]- R[0];
	minv = R[0];
	
	
	
	for(j = 1; j < n; j++){
	   
	   
	   if(maxv < R[j] - minv){
	    maxv = R[j] - minv;
	
	    } else { maxv = maxv;
	    
	    }
	    
	    
	    if(minv > R[j]){
	    minv = R[j];
	    
	    } else { minv = minv;
	
	    }
	
	}
	
	
	printf("%d\n", maxv);
	return 0;
}
