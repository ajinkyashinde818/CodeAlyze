#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a,b,k;
    int i;
    int r;
        int l;

    int j=1;
    int x[101] = {0};
    int y[101] = {0};
    int z[101] = {0};

    // スペース区切りの整数の入力
    scanf("%d %d %d",&a,&b,&k);

   for(i=1;i<=100;i++){
        if(a % i == 0){
              x[i]++;
              //printf("x %d\n",i);
        }
   }

   for(i=1;i<=100;i++){
        if(b % i == 0){
              y[i]++;
             //printf("y %d\n",i);
        }
   }

   for(i=1;i<=100;i++){
        if(x[i] == y[i]){
            if(x[i] == 0){
                continue;
            }
              z[j] = i;
              j++;
        }
   }
   
    // 出力
    printf("%d\n",z[j-k]);
    return 0;
}
