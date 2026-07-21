#include <stdio.h>

int main(void){
        int a,b,k,i,n=0;

        scanf("%d%d%d",&a,&b,&k);
        for(i=100;i>=1;i--){
                if((a%i==0)&&(b%i==0))
                        n++;
                if(n==k){
                        printf("%d\n",i);
                        break;
                        }
                }
        return 0;
        }
