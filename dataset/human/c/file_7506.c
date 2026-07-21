#include<stdio.h>

int main(){

    int a[10000],data,i,j,N;
    i==0;
    while(1){ 
        scanf("%d", &data);
        if(data==0){    break;
        }
        a[i]=data;
        i++;
    }

    for(j=0;j<i;j++){
        printf("Case %d: %d\n",j+1,a[j]);
        }

    return 0;
}
