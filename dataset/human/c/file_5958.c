#include <stdio.h>
int main(){
    int n, i, min, maxProfit;
    scanf("%d", &n);
    int input[n];
    for(i=0;i<n;i++){
        scanf("%d", &input[i]);
    }
    min = input[0];
    maxProfit = input[1] - min;
    for(i=1;i<n;i++){
        if(input[i] - min > maxProfit) maxProfit = input[i] - min;
        if(input[i] < min) min = input[i];
    }
    printf("%d\n",maxProfit);
    return 0;
}
