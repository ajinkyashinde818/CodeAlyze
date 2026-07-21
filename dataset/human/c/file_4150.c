#include <stdio.h>
int main(void)
{
    int a, b, k, cnt=0, i=1, q[1000];

    scanf("%d%d%d", &a, &b, &k);

    for(i=1;i<=100;i++){
        if(a%i==0 && b%i==0){
            q[cnt]=i;
            cnt++;
        }
    }
        

    
    printf("%d\n", q[cnt-k]);
    return 0;
}
