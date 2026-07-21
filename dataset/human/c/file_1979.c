#include <stdio.h>
int main(){
long long int a,b,c,sum=0;
  scanf("%lld%lld%lld",&a,&b,&c);
  if(b<c){
  sum=sum+(b+b);
  c=c-b;
  if(c>a){
    sum=sum+(a+1);
     printf("%lld",sum);
  }
    else if(c==a){
      sum=sum+c;
       printf("%lld",sum);
    }
    else{
      sum=sum+c;
       printf("%lld",sum);
    }
  }
  else if(b==c){
    sum=sum+(b+b);
     printf("%lld",sum);
  }
  else{
    sum=sum+(c+c);
    b=b-c;
    sum=sum+b;
     printf("%lld",sum);
  }

}
