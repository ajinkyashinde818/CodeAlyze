#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k,i;
    char s[11];
    char c;
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);

    c = s[k-1];

    for(i=0;i<n;i++){
        if(s[i]!=c){
            s[i] = '*';
        }
    }

    printf("%s\n",s);
    return 0;
}
