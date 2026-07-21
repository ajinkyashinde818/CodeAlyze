#include<stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int i, a[N];
    for(i=0;i<N;i++){
      scanf("%d", &a[i]);
      // printf("%p\n", &a[i]);
      // printf("%d\n", a[i]);
    }

    int flg[N];
    for(i=0;i<N;i++){
      flg[i]=0;
    }
    int count=0, next=a[0];
    flg[0]=1;
    for(i=0;i<N;i++){
      count++;
      if(next==2){
        break;
      }

      if(flg[next-1]==1){
        count=-1;
        break;
      }else{
        flg[next-1]=1;
      }

      next=a[next-1];

      if(i==N-1){
        count=-1;
        break;
      }


    }

    printf("%d\n", count);

    return 0;
}
