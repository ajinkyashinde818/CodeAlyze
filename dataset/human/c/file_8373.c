#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    scanf("%d",&k);
    
    for(int i=0;i<n;i++){
        if(s[i] != s[k-1]){
            s[i] = '*';
        }
    }
    printf("%s",s);
    return 0;
}
