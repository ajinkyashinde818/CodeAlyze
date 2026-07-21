#include<stdio.h>

int main(void)
{
    int i;
    int n, k;
    scanf("%d", &n);

    char str[n];
    scanf("%s", str);
    scanf("%d", &k);
    
    for(i = 0;i < n; i++)
    {
        if(str[i] != str[k-1])
            str[i] = '*';
    }
    
    printf("%s\n", str);
    
    return 0;
}
