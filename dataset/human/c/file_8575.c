#include <stdio.h>
int main(void){
    // Here your code !
    int n,a[100001],i,t,s=1;
    int sum = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        t=a[s];
        s=t;
        sum += 1;
        if(s==2){
            break;
        }
        else if(i == n){
            sum = -1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
