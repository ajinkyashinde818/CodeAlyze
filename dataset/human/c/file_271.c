#include<stdio.h>




long int myabs(long int a)
{
  if(a>0)return a;
  return -a;
}

int main(){
  int n;
  scanf("%d",&n);

  long int a[n],i,min=1000000000,sum=0;
  int count=0,flag=1;
  for(i=0;i<n;i++)
    {
      scanf("%ld",&a[i]);
      if(a[i]==0) flag=0;
      if(a[i]<0 && flag)
	{
	  a[i]=myabs(a[i]);
	 count++;
	}
      else a[i]=myabs(a[i]);
      sum+=a[i];
      if(a[i]<min)
	min=a[i];

    }

  if(flag && count%2==1)
    sum-=min*2;
  printf("%ld",sum);
}
