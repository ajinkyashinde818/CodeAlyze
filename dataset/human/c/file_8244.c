#include<stdio.h>
int i,k,n;
char s[10];
int main(void){
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for(i = 0;i < n;i++){
        if(s[i] != s[k-1]){
        s[i] = '*';
        }
    }
    printf("%s",s);
}
