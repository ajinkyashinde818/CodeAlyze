#include <stdio.h>

int main(){
    int n, price, i, min, max;
    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&price);
        if(i==0) min = price;
        else{
            if(i==1) max = price - min;
            if(min > price) min = price;
            else if(max < price - min) max = price - min;
        }
    }

    printf("%d\n", max);
    return 0;
}
