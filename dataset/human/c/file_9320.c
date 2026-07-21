#include<stdio.h>
 int main(void)
 {
     long h[100000];
     int N,K,L=0,i;

     scanf("%d%d",&N,&K);

     for(i=0;i<N;i++)
       scanf("%ld",&h[i]);

     for(i=0;i<N;i++)
       if(K<=h[i]) L++;

     printf("%d\n",L);

     return 0;
 }
