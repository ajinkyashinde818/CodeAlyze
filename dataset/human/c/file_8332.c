#include <stdio.h>

int main(void){
    int n, k, i;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    scanf("%d", &k);
    for(i=0;i<n;i++){
        if(s[k-1] == s[i]){
            printf("%c", s[i]);
        } else{
            printf("*");
        }
    }
    
    return 0;
}
