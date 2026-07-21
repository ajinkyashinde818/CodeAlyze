#include<stdio.h>
int main()
{
  int a,b,k,a_,amari,kouyaku,answer;
  scanf("%d %d %d",&a,&b,&k);
  if (a>b)  //bよりaを小さくする a<b
  {
    a_=a;
    a=b;
    b=a_;
  }
  while(1)
  {
    amari=b%a;
    if (amari==0)
    {
      kouyaku=a;
      break;
    }
    b=amari;
    a_=a;
    a=b;
    b=a_;
  }
  for( answer=kouyaku; answer>=1; answer-- )
  {
    if( kouyaku%answer == 0 ) k--;
    if (k==0) break;
  }
  printf("%d",answer);
  return 0;
}
