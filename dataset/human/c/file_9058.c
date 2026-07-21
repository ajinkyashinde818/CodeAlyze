#include<stdio.h>
int main(){
int N,k,i;
  scanf("%d %d",&N,&k);
  int h[N],a1,a2;
  a1=0;
 for(i=1;i<=N;++i){
   scanf("%d",&h[i]);
     if(h[i]>=k){
       a2=a1+1;
       a1=a2;
       }
       }
       printf("%d\n",a1);
}
