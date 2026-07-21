#include <stdio.h>
#define N 200000

int main(){
	int i, n, maxv, minv, r[N];
	
	scanf("%d", &n);
	
	for( i = 0; i < n; i++ ){
	scanf("%d", &r[i]);
    }
    
    maxv = r[1] - r[0];
    minv = r[0];
    
    for( i = 1; i < n; i++ ){
    if(maxv < r[i] - minv)
        maxv = r[i] - minv;
	if(minv > r[i])
	    minv = r[i];
    }
    
    printf("%d\n", maxv);
	    
	return 0;
}
