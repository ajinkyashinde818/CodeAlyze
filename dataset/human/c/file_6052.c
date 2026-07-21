// Maximam Profit
#include <stdio.h>

int maxProfit(int*, int);

int main(){
    int i, n, A[200000], max;
    scanf("%d", &n);
    for(i=0; i < n; i++){
        scanf("%d", &A[i]);
    }
    max = maxProfit(A, n); // 最大の利益を求める
    printf("%d\n", max);
    return 0;
}

int maxProfit(int *A, int n){
    int i, num, max, min;
    min = A[0];
    for(i=1; i < n; i++){
        if(i == 1)max = A[i]-min; // 最大値を更新
        else if(A[i]-min > max)max = A[i]-min; // 最大値を更新
        if(min > A[i])min = A[i]; // 最小値を更新
    }
    return max;
}
