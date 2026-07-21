#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    int n,k;
    char s[20];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=s[k-1]){s[i]='*';}
    }
    printf("%s",s);
}
