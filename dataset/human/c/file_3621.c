#include<stdio.h>
long long int GCD(long long int a, long long int b)
{
     if(a%b==0)
        return b ;
  else
      return   GCD(b,a%b);

}

int main()
{
   long long int x,y, temp;
   scanf("%lld%lld", &x, &y);
   if(x<y)
   {
    temp=y;
    y=x;
    x=temp;
   }
     printf("%lld\n", (x*y)/GCD(x,y));
    return 0;


}
