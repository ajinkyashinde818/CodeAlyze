#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main()
{   int n,a,b,i,m,k,x,y,c;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        if(s[i]==s[k-1]){
            printf("%c",s[i]);
        }else{
            printf("*");
        }
    }

    return 0;
}
