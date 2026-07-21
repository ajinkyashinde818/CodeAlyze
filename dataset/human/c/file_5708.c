#include <stdio.h>
#include <limits.h>

int main(void){
    int n, i, tmp, tmp2;
    int profit = INT_MIN;
    int min = INT_MAX;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        tmp2 = tmp-min;
        if(tmp2>profit){
            profit=tmp2;
        }
        if(tmp<min)min=tmp;
    }
    printf("%d\n",profit);
    return 0;
}
