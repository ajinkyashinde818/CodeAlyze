#include<stdio.h>
#include <limits.h>
int gcd(long int p,long int q){
long int r; r=p%q;
while(r>0){p=q;q=r;r=p%q;}
return q;}

int main(){
long int A,a,b,c;
scanf("%ld %ld",&a,&b);
c=a*b;
A=c/gcd(a,b);
printf("%ld", A);
return 0;}
