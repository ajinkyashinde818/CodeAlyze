#include <stdio.h>
#define MAX_L 200001
#define MIN_PRO -1000000000
int R[MAX_L];
int main() {
    int n;
    int temp;
    scanf("%d", &n);
    int profit = MIN_PRO;
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &R[i]);
    }
    int min = R[0];
    for(int j=1;j<n;j++)
    {
        temp = R[j] - min;
        if(profit<temp){profit = temp;}
        if(R[j]<min){min=R[j];}
    }
    printf("%d\n", profit);
    return 0;
}
