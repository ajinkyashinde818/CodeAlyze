#include<stdio.h>

#define Max 200000
int main ()
{
  int j,max,min,num,number[Max];

  scanf("%d",&num);


  for(j=0;j<num;j++)
    {
      scanf("%d",&number[j]);
    }



  for(j=1;j<=num-1;j++)
    {

          max=number[1]-number[0];
          min=number[0];

          for(j=1;j<=num-1;j++)
        {

          if(max<number[j]-min)
            {
              max=number[j]-min;
            }

          if(min>number[j])
            {
              min=number[j];
            }

        }

        }
        printf("%d\n",max);

     return 0;
   }
