#include<stdio.h>


 int main(){
     int n,i,j;
     int R[200001],Max,Min;
     scanf("%d",&n);
     for(i=0;i<n;i++){
              scanf("%d",&R[i]);
              }
     Min=R[0];
     Max=R[1]-Min;
     for(i=1;i<n;i++){
              if(R[i]-Min>Max)Max=R[i]-Min;
              if(Min>R[i])Min=R[i];
              }
     printf("%d\n",Max);
     return 0;
     }
