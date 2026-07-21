#include<stdio.h>

int main(void){
    int N;
    //数の上限
    scanf("%d",&N);
    int num[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&num[i]);
    }
    int minv = num[0];
    int maxv = num[1] - num[0];
    for(int j = 1;j < N;j++){
      maxv = maxv > (num[j] - minv)?maxv:num[j] - minv;
      minv = minv < num[j]?minv:num[j];
    }
    printf("%d\n",maxv);
}
