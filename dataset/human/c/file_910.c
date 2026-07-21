#include <stdio.h>

int n, x, y, imos[100003], table[100002];

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y); y++;
        
        imos[x]++;
        imos[y]--;
    }
    
    for(int i = 1; i <= 100001; i++)
    {
        table[i] = table[i - 1] + imos[i];
    }
    
    int ret = 0;
    
    for(int i = 1; i <= 100001; i++)
    {
        if(i - 1 <= table[i])
        {
            ret = i - 1;
        }
    }
    
    printf("%d\n", ret);
    
    return 0;
}
