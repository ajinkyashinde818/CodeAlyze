#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int a,n,k,aa,bb;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    scanf("%d",&k);
    k-=1;
    for(a=0;a<n;a++){
        aa=s[k];
        bb=s[a];
        if(aa==bb){
            printf("%c",s[a]);
        }else{
            printf("*");
        }
    }
    return 0;
}
