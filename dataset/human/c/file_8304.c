#include <stdio.h>


int main(void){
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    char tmp = s[k - 1];
    for(int i = 0; i < n; i++){
        if(s[i] != tmp){
            s[i] = '*';
        }
    }
    printf("%s\n", s);
    return 0; 
}
