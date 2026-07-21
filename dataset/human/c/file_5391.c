#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 15
int min(int a,int b){
    if(a<b) return a;
    else return b;
}

int main(){
    int N,M,X;
    int C[MAX];
    int A[MAX][MAX];
    int ans = 1000000000;
    scanf("%d %d %d",&N,&M,&X);
    for(int i=1;i<=N;i++){
        scanf("%d",C+i);
        for(int j=1;j<=M;j++)
            scanf("%d",&A[i][j]);
   }
   for(int bit=1;bit<(1<<N);bit++){
       int state[MAX] = {0};
       int money = 0;
       for(int i=1;i<=N;i++){
           if(bit & 1<<(i-1)){
               money += C[i];
               for(int j=1;j<=M;j++)
                    state[j] += A[i][j];
           }
       }
       bool f = true;
       for(int j=1;j<=M;j++){
            if(state[j] < X){
                f = false;
                break;
            }
       }
       if(f) ans = min(ans,money);
   }
   if(ans == 1000000000) printf("-1");
   else printf("%d",ans);
}
