#include<stdio.h>    
    
int main(void) {    
    int k;    
    int s;    
    scanf("%d", &k);    
    scanf("%d", &s);    
    int ans = 0;    
    for(int x = 0; x <= k; x++) {    
        for(int y = 0; y <= k; y++) {       
            int z = s-x-y;   
            if(z <= k && z >= 0)
                ans++;
        }                                   
    }    
    printf("%d", ans);    
}
