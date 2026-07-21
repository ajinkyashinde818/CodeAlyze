#include<stdio.h>

int main(void)
{
    
    int n, max, min, diff, j, i;
    
    scanf("%d", &n);
    
    int R[n];
    
    for(i =0 ; i<n; i++)
    {
        scanf("%d", &R[i]);
    }
    
    max = R[1]-R[0];
    min = R[0];
    
    for(j=1; j<n; j++)
    {
        diff = R[j]-min;
        
       if(max < diff)
       {
           max =diff;
       }
       
       if(min > R[j])
       {
           min = R[j];
       }
       
    }
    
    printf("%d\n", max);
    
    return 0;
    
}
