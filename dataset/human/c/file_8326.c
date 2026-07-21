#include <stdio.h>
int main (void) 
{
    int n,k;
    char s[11];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for (int i =0 ; i < n; i++) {
        if(s[k -1] != s[i])    s[i] = '*';
    }
    printf("%s",s);
    return 0;
}
