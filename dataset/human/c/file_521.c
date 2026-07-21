#include<stdio.h>
long long int abs(long long int a){
  return a<0?-1*a:a;
}
int main(){
  int a;
  scanf("%d",&a);
  long long int b[a],c=400000000000000;
  long long int d=0LL,e=0LL;
  for(int i=0; i<a; i++){
    scanf("%lld",&b[i]);
    e+=b[i];
  }
  for(int i=0; i<a-1; i++){
    d+=b[i];e-=b[i];
    if(abs(d-e)<c){c=abs(d-e);}
  }
  printf("%lld",c);
  return 0;}
