#include<stdio.h>

int main(void){
    int n, R, min = 1000000000, max = -1000000000;
    
    scanf("%d",&n);
    scanf("%d",&R);
    min = R;
    for(int i = 0; i < n - 1;i++)
    {
        scanf("%d",&R);
        if(max < R - min)
        {
            max = R - min;
        }
        if(min > R)
        {
            min = R;
        }
        
    }
    
    printf("%d\n", max);
    return 0;
}
