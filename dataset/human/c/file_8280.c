#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n,k;
    char s[11];
    int i;
    scanf("%d",&n);
    // s=(char*)malloc(sizeof(char)*n);
    scanf("%s",s);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    printf("%s\n",s);
    return 0;
}
