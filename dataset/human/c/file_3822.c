#include<stdio.h>
int gcd(int s,int t){
  if(s<t){
    int w=s;
   	s=t;
    t=w;
  }
  if(s%t!=0)return gcd(t,s%t);
  else return t;
}
int main(void){
int a,b;
  scanf("%d%d",&a,&b);
  int x=gcd(a,b);
  //printf("%d\n",x); 
  long long  ans=(long long)a/x*b;
  printf("%lld",ans);
  return 0;
}
