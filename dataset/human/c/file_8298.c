#include <stdio.h>
int main(void)
{
    int n, k, i=0;
    char s[11], c[2];
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);

    while(s[i]!='\0'){
        if(i==k-1) c[0]=s[i];
        i++;
    }
    i=0;
    while(s[i]!='\0'){
        if(s[i]!=c[0]){
            s[i]='*';
        }
        i++;
    }
    printf("%s\n",s);    
    return 0;
}
