#include <stdio.h>
#include <limits.h>
#define N 8

int CAPACITY[N] = {4, 1, 4, 1, 2, 1, 2, 1};
#define CAPACITY(a,offset) CAPACITY[(a+offset)%N]

int main(void)
{
     int clients[N];

     while(~scanf("%d",clients)){
          int n, min=INT_MAX, minV=INT_MAX, minN;

          for(n=1; n<N; n++) scanf("%d",clients+n);

          for(n=0; n<N; n++){
               int i, t=0, v=0;

               for(i=0; i<N; i++){
                    v = v*10 + CAPACITY(i,n);
                    if(CAPACITY(i,n) < clients[i])
                         t += clients[i] - CAPACITY(i,n);
               }

               if(min>t || (min==t && minV>v))
                    min = t, minV = v, minN = n;
          }

          printf("%d",CAPACITY(0,minN));
          for(n=1; n<N; n++)
               printf(" %d",CAPACITY(n,minN));
          puts("");
     }

     return 0;
}
