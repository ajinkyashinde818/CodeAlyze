#include<stdio.h>
    int main()
    {
        int N,i,j,k;
        int data[100001];
        scanf("%d", &N);
        for(i = 0;i < N;i++){
        scanf("%d", &data[i]);
        }
        j = data[0];
        k = data[0];
        for(i = 0;i < N;i++){
          if(k == 2){
          printf("%d \n",i+1);
          break;
          }
          if(i == N-1) printf("-1\n");
          k = data[j-1];
          j = k;
        }
        return 0;
    }
