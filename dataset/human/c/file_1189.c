#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101],t[101],a;
    int i,j;
    scanf("%s%s",s,t);
    for(i=0;i<strlen(s)-1;i++){
        for(j=strlen(s)-1;j>i;j--){
            if(s[j-1]>s[j]){
                a=s[j-1];
                s[j-1]=s[j];
                s[j]=a;
            }
        }
    }
    for(i=0;i<strlen(t)-1;i++){
        for(j=strlen(t)-1;j>i;j--){
            if(t[j-1]<t[j]){
                a=t[j-1];
                t[j-1]=t[j];
                t[j]=a;
            }
        }
    }
    if(strcmp(t,s)>0)puts("Yes");
    else puts("No");
    return 0;
}
