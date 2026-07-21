#include <stdio.h>

int main(void)
{
    int i = 0;
    int n = 0;
    int maxv = -1000000010;
    int minv = 0;
    int R[200010];
    
    scanf("%d", &n);
    scanf("%d", &R[0]);
    
    minv = R[0];
    
    for(i = 1; i < n; i++){
        scanf("%d", &R[i]);
        if(maxv < R[i] - minv){
            maxv = R[i] - minv;
        }
        if(minv > R[i]){
            minv = R[i];
        }
    }
    
    printf("%d\n", maxv);
    
    return 0;
}
