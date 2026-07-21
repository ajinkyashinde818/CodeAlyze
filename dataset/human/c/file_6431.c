#include <stdio.h>

int main (void){
    long int n, i, dif = -9999999999999, minp = 999999999999;
    
    scanf("%ld", &n);
    
    int r[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
        if(minp > r[i-1] && i >= 1){ minp = r[i-1]; } 
        
        if(dif < r[i] - minp) dif = r[i] - minp;
        

    }
    
    printf("%ld\n", dif);
    return 0;
    
}
