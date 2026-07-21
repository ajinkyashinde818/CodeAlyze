#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int n,i,min,max,x;
    
    scanf("%d",&n);
    
    scanf("%d",&min);
    scanf("%d",&x);
    
    max = x - min;
    min = fmin(min, x);
    
    for (i=2; i<n; i++) {
        scanf("%d",&x);
        
        max = fmax(max, x - min);
        
        min = fmin(min, x);
        
    }
    
    printf("%d\n",max);
    return 0;
}
