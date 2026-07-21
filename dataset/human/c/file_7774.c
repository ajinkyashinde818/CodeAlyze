#include <stdio.h>

int main(void){
    int n,i;
    scanf("%d",&n);
    int k[n],p[n];
    for(i = 0;i < n;i++)
        scanf("%d %d",&k[i],&p[i]);
    for(i = 0;i < n;i++){
        if(k[i]%p[i] == 0){
            printf("%d\n",p[i]);
            continue;
        }
        printf("%d\n",k[i] % p[i]);
    }
    return 0;
}
