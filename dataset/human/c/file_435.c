#include<stdio.h>
int main(){
  long long n,M=1e9+7,i,a=0,b=1,c,d=1;
  char s[200010]={};
  scanf("%lld %s",&n,s);
  for(i=0;i<n;i++)b=(b*(i+1))%M;
  for(i=0;i<2*n;i++){
    if(s[i]=='B')c=1;
    else         c=0;
    if((c+a)%2)a++;
    else{
      if(a==0)goto END;
      d=(d*a)%M;
      a--;
    }
    //printf("%lld\n",a);
  }//printf("%lld %lld\n",d,b);
  if(a)goto END;
  printf("%lld\n",(d*b)%M);
  return 0;
 END:;
  printf("0\n");
  return 0;
}
