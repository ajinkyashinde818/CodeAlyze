#include <stdio.h>
int main(void){
    char c[11];
    int n,k,i,m;
    
    scanf("%d",&n);
    scanf("%s",c);
    scanf("%d",&k);
    
    m=c[k-1];
    
    for(i=0;i<n;i++){
        if(c[i]!=m){
            c[i]='*';
        }
        printf("%c",c[i]);
    }
    
}
