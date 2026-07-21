#include <stdio.h>

int main(){
    
    int i,j = 0;
    long x[20000];
    
    for(i=0;i<20000;i++){
        
        scanf("%ld",&x[i]);
        j++;
        
        if(x[i] == 0)
            break;
    }
    
    
    for(i = 0; i < j-1; i++){
        printf("Case %d: %ld\n",i+1,x[i]);
    }
    
    return 0;
    
}
