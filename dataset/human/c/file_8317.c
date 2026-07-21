#include<stdio.h>
#define N 11//文字列の長さ

int main(void){
    int n,k;//nは文字列の長さ、kはk番目の文字を置き換えない
    int i;//iはループ用 
    char s[N],t;//sは与えられた文字列,tはk番目の文字の保存

    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);

    t=s[k-1];
    for(i=0;i<n;i++){
        if(s[i]!=t)
        s[i]='*';
    }
    printf("%s",s);
    return 0;
    
}
