#include <stdio.h>
#define N 200000
//#define Num 1000000000
int data[N];
int main(){

  int num,i,j,max,min;

  //int data[N];

  scanf("%d",&num);

  for(i = 0 ; i < num ; i++)
    {
      scanf("%d",&data[i]);

    }


  max = data[1] - data[0];
  min = data[0];


  for(j = 1 ; j < num ; j++)
    // {
    //for(i = 0 ; i <= j-1 ; i++)
	{
	  if(data[j] - min > max)max = data[j] - min;
	  if(min > data[j])min = data[j];
	  
	  //	}
    }

  // if(max <= 0)max == -1;

  printf("%d\n",max);

  return 0;
}
