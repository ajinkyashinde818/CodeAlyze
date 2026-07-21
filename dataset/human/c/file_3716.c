#include<stdio.h>
int main()
{
          long long int i,num1,num2,result,temp,max;
          scanf("%lld%lld",&num1,&num2);
          i=1;
          if(num1 > num2)
          {
                    max = num1;
          }
          else
          {
                     max = num2;
          }
          while(1)
          {
              if((num2 * i) % num1 == 0)
              {
                        temp = i;
                        break;
              }
              i++;
          }
          result = num2 * temp;
          printf("%lld\n",result);
}
