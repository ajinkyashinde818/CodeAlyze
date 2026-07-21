#include<stdio.h>
#include<stdlib.h>
long long int a,b,c;
int main(void){
scanf("%lld",&a);
 b=a/11;
 c=a%11;
 if(c==0){
 c=0;
 }else if(c<=6){
 c=1;
 }else {
 c=2;
 }
 printf("%lld",b+b+c);
 return 0;
}
