#include<stdio.h>
int gcd(int a,int b){
  if(a<b) return gcd(b,a);
  if(b==0) return a;
  return gcd(b,a%b);
}

int main(){
  int a,b,k;
  scanf("%d %d %d",&a,&b,&k);
  int d=gcd(a,b),i=0;
  while(k){
    i++;
    if(d%i==0) k--;
  }
  printf("%d",d/i);
}
