#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int n=0,k=0;
    int h[10000000];
    int result = 0;

    scanf("%d %d",&n,&k);

    while(i < n)
    {
        
        if(i < n-1)scanf("%d ",&h[i]);
        else scanf("%d",&h[i]);
        if(h[i] >= 1 && h[i] <= 500){
            if(h[i] >= k) result++;
            else{}
        }
        i++;
    }

    printf("%d\n",result);

    return 0;
    
}
