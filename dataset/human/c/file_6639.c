#include <stdio.h>
#define N 200000

int main(){
    int t,i,j;
    int data[N],max,min;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&data[i]);
        if(data[i] < 1 || data[i] > 1000000000) return 0;
    }

    max = data[1] -data[0];

    min = data[0];
    
    for(j=1;j<t;j++){
        if(max < data[j] - min) max = data[j] - min;
        if(min > data[j] ) min = data[j];
    }
    
    
    
    

    
    printf("%d\n",max);
    return 0;
}
