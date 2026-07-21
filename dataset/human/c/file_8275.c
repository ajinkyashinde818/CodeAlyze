#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int main(void){
    int n,k;
    char s[20];
    scanf("%d %s %d",&n,s,&k);
    char moji[2];
    moji[0]=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=moji[0]) s[i]='*';
    }
    printf("%s\n",s);
    return 0;
}
