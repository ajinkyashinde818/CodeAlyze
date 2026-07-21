#include <stdio.h>
int main(void){
    int n,k,i;
    scanf("%d\n",&n);
    
    char s[n];
    for (i=0; i<n; i++){
        scanf("%c",&s[i]);
    }
    
    scanf("%d",&k);
    
    for (i=0; i<n; i++){
        if(s[i]!=s[k-1]){
            s[i] = '*';
        }
        printf("%c",s[i]);
    }
    
    return 0;
}
