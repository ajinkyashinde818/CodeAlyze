#include <stdio.h>
int main(void){
    int primemap[1000000]={0},i,sum=0,j;
    primemap[0]=1;primemap[1]=1;
    for(i=2;i*i<999999;i++){
        j=2;
        while(i*j <= 999999){
            primemap[i*j]=1;
            j++;
        }
    }
    while(1){      
        scanf("%d",&j);
        if(j==0)
            break;
        for(i=2;i<=999999;i++){
                if(primemap[i] == 0){
                    sum+=i;
                    j--;
                    if(j == 0)
                        break;
                }
            }
            printf("%d\n",sum);
            sum=0;
    }
    return 0;
}
