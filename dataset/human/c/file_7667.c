#include<stdio.h>

int main()

{
    int x[10000],i=0;
    while(1){
        scanf("%d",&x[i]);
        if(x[i]==0){break;}
        i++;
    }
    int k = i;
    for(i = 0;i<k;i++){
        printf("Case %d: %d\n",i+1,x[i]);
    }
    return 0;
}
