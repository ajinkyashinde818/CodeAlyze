#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m;  
  return (int)s;
}
int main(){
  long long n,m,s,M=1e9+7;
  scanf("%lld %lld",&n,&m);
  s=n+m;
  if(s%3)goto END;
  n-=s/3;
  m-=s/3;
  if(n<0||m<0)goto END;
  printf("%d\n",aCb(n+m,m,M));
  return 0;
 END:;
  printf("0\n");
  return 0;
}
