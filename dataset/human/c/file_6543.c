#include <stdio.h>
#define S 2000000

int main(void)
{
    int i, n;
    int min, diff, N[S];
    
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &N[i]);
    
    min=N[0];
    diff=N[1]-N[0];
    for(i=1; i<n; i++){
            if(min>N[i]) min=N[i];
            else if(diff<N[i]-min) diff=N[i]-min;
        }
    printf("%d\n", diff);
    return 0;
}
