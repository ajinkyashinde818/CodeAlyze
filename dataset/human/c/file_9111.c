/* 142b */
#include<stdio.h>
int main(void)
{
  int n,k,h[100000],i,f;
 scanf("%d %d",&n,&k);
 f=0;
 for(i=0;i<n;i++){
   scanf("%d",&h[i]);
   if(h[i]>=k){
     f++;
   }
 }
 printf("%d\n",f);
 return 0;
}
