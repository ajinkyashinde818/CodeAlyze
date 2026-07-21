#include <stdio.h>

#define max 200000
int maxProfit(int[]);

int main(){
    int n,maxv,minv;
    int r[max];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&r[i]);
    }

    maxv = r[1] - r[0];
    minv = r[0];
    for(int j=1;j<n;j++){
        if(maxv <= r[j]-minv)maxv = r[j] - minv;
        if(minv >= r[j])minv = r[j];
    }

    printf("%d\n",maxv);

    return 0;
}
