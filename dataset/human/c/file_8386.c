#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,k,i;
    scanf("%d",&n);
    char s[n];
    scanf("%s %d",&s,&k);
    for(i=0; i<n; i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    printf("%s\n",s);
    return 0;
}
