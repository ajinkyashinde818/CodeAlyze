#include<stdio.h>

int main(void)
{
  long long int X,Y;
  long long int a,b,i;
  scanf("%lld%lld",&X,&Y);
  long long int N=1;
  
  if((2*Y-X)%3!=0||(2*X-Y)%3!=0||2*X<Y||2*Y<X){
    N=0;
  }
  
  a=(2*Y-X)/3;
  b=(2*X-Y)/3;
  
  long long int S=1,T=1;
  for(i=b+1;i<=a+b;i++){
    S=S*i;
    S=S%1000000007;
  }
  for(i=1;i<=a;i++){
    T=T*i;
    T=T%1000000007;
  }
  
  long long int A[30];
  long long int P;
  A[0]=T;
  for(i=1;i<=29;i++){
    A[i]=A[i-1]*A[i-1];
    A[i]=A[i]%1000000007;
  }
  P=A[0];
  P=P%1000000007;
  P=P*A[2];
  P=P%1000000007;
  P=P*A[9];
  P=P%1000000007;
  P=P*A[11];
  P=P%1000000007;
  P=P*A[14];
  P=P%1000000007;
  P=P*A[15];
  P=P%1000000007;
  P=P*A[17];
  P=P%1000000007;
  P=P*A[19];
  P=P%1000000007;
  P=P*A[20];
  P=P%1000000007;
  P=P*A[23];
  P=P%1000000007;
  P=P*A[24];
  P=P%1000000007;
  P=P*A[25];
  P=P%1000000007;
  P=P*A[27];
  P=P%1000000007;
  P=P*A[28];
  P=P%1000000007;
  P=P*A[29];
  P=P%1000000007;
  
  S=S*P*N;
  S=S%1000000007;
  
  printf("%lld",S);
  
  return 0;
}
