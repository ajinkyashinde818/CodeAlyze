#include <stdio.h>

int main(void)
{
    int k,s;
    scanf("%d%d",&k,&s);
    int c=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int l=s-i-j;
            if(0<=l&&l<=k) c++;
        }
    }
    printf("%d\n",c);
    
    return 0;
}
