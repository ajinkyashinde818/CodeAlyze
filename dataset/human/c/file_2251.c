#include <stdio.h>

int min(int a, int  b, int c){
   int min=a;
   if(min>b) min=b;
   if(min>c) min=c;
   return min;
}

int main(void)
{
   char map[1000][1001];
   int space[1000][1000];
   int N;
   int i, j;
   int max;
   
   while(1){
      scanf("%d", &N);
      if(N==0) break;

      for(i=0; i<N; i++) scanf("%s", map[i]);

      max=0;
      for(i=0; i<N; i++){
         if(map[i][0]=='.'){
            space[i][0]=1; max=1;
         }
         else space[i][0]=0;
      }
      for(i=0; i<N; i++){
         if(map[0][i]=='.'){
            space[0][i]=1;
            max=1;
         }
         else space[0][i]=0;
      }

      for(i=1; i<N; i++){
         for(j=1; j<N; j++){
            if(map[i][j]=='.') space[i][j]=min(space[i-1][j-1], space[i-1][j], space[i][j-1])+1;
            else space[i][j]=0;
            if(max<space[i][j]) max=space[i][j];
         }
      }
      printf("%d\n", max);
   }
   return 0;
}
