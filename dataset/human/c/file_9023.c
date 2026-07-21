#include<stdio.h>
int h[100005];
int main()
{
    int N,K;
    int i,c=0;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
         scanf("%d",&h[i]);
    }
            for(i=0;i<N;i++)
          {
              if(h[i]>=K)
              c++;
          }
        printf("%d",c);
        return 0;
}
