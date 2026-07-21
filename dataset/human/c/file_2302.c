#include <stdio.h>

int main(){
    int n, k, s;
    scanf("%d%d%d", &n,&k,&s);
    for(int i = 0; i < k; i++){
        printf("%d ", s);
    }
    for(int i = k; i < n; i++){
        if(s == 1000000000) printf("%d ", s-1);
        else printf("%d ", s+1);
    }
    return 0;
    
}
