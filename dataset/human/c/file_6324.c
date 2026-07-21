#include <stdio.h>

int main ()
{
    long int max = -2000000000,min,num = 0;
    
    scanf("%ld",&num);
    
    long int val[num];
    
    for(int i = 0;i<num;i++)
    {
        scanf("%ld",&val[i]);
        
    }
    
    min = val[0];
    
    for(int i = 1; i<num ;i++)
    {
        
        if(max < val[i] - min)
        {
            max  = val[i] - min;
        }
        
        if(min>val[i])
            min = val[i];

    }
    printf("%ld\n",max);
    return 0;

}
