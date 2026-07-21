#include<stdio.h>
int main(void){
    int n,k,tmp,i;
    char str[10];
    scanf("%d",&n);
    scanf("%s",str);
    scanf("%d",&k);
    tmp=str[k-1];
    for(i=0;i<n;i++){
        if(str[i]!=tmp){
            str[i]='*';
        }
    }
    printf("%s",str);
    return 0;
    
}
