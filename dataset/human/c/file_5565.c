#include <stdio.h>
#include <math.h>

int primecheck(int n){
    int i;
    
    if(n==0||n==1)return 0;

    for(i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}

int main(void){
    int i,n,cnt,sum;
    
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        
        for(i=sum=cnt=0;cnt<n;i++){
            if(primecheck(i)==1){
                cnt++;
                sum+=i;
            }
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
