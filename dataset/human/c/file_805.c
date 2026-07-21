#include<stdio.h>
int main(){
  int d,g,p[11],c[11],x=1<<29,t,i,j,s,n;
  scanf("%d%d",&d,&g);g/=100;
  for(i=1;i<=d;i++){scanf("%d%d",&p[i],&c[i]);c[i]/=100;}
  for(i=0;i<1<<d;i++){
    s=n=0;for(j=1;j<=d;j++)if((1<<(j-1))&i){n+=p[j];s+=j*p[j]+c[j];}
    if(s<g){
      for(j=d;j>0;j--)if(((1<<(j-1))&i)==0){
        if(j*(p[j]-1)>=g-s)n+=(g-s)/j+((g-s)%j!=0);
        else n=1<<29;
        j=0;
      }
    }
    x=n<x?n:x;
  }
  printf("%d",x);
}
