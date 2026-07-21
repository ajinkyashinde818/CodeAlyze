#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[4],t;
    int i,j;
    scanf("%s",s);
    for(i=0;i<2;i++){
        for(j=2;j>i;j--){
            if(s[j-1]>s[j]){
                t=s[j-1];
                s[j-1]=s[j];
                s[j]=t;
            }
        }
    }
    puts(strcmp(s,"abc")?"No":"Yes");
    return 0;
}
