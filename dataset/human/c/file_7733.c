#include <stdio.h>

int n, k, p;

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        scanf("%d", &p);
        
        int r = 0;
        
        while(k--)
        {
            r++;
            
            if(r > p) { r = 1; }
        }
        
        printf("%d\n", r);
    }

    return 0;
}
