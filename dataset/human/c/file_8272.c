#include<stdio.h>
int main(void){
    int n,k;
    char val;
    char s[1000010];
    scanf("%d",&n);
    scanf("%s",&s);
    scanf("%d",&k);
    val=s[k-1];
    int i;
    
    for(i=0;i<n;i++)
    {
        if(s[i]!=val)
        {
            s[i]='*';
        }
    }
    
    printf("%s",s);
    
    return 0;
}
