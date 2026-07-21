#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
  int a,b,c,i;
  scanf("%d %d %d",&a,&b,&c);
  for(i=gcd(a,b);c;i--){
    if(a%i==0&&b%i==0)c--;
  }
  printf("%d\n",i+1);
  return 0;
}
