#include <stdio.h>
int main (){
    int n,k;
    char s[11];
    char tmp;
    int i=0;

    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    tmp = s[k-1];
    for(i=0; i <n ; i++){
        if (s[i] != tmp) {
            s[i] = '*';
        }
        printf("%c",s[i]);
    }
    return 0;
}
