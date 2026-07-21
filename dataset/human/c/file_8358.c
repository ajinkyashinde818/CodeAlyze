#include <stdio.h>

int main(void){
    int n;
    char str[10];
    int k;
    char t;
    int i;

    scanf("%d",&n);
    scanf("%s",str);
    scanf("%d",&k);

    k--;

    t = str[k];
    
    for(i = 0;i < n;i++){
        if(str[i] != t){
            str[i] = '*';
        }
    }

    printf("%s",str);

    return 0;
}
