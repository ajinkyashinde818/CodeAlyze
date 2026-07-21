#include<stdio.h>
#include<string.h>
#include<math.h>

 
int main(){
   long long int a,aa,b,bb,r,tmp;
   scanf("%lld %lld", &a,&b);
   bb = b;
   aa = a;
   if(a<b){
    tmp = a;
    a = b;
    b = tmp;
   }
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  	tmp = aa*bb;
    printf("%lld", tmp/b);
	return 0;
}
