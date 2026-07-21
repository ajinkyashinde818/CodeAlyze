#include<stdio.h>
int main()
{
  int n,flag=0;
  int a,b;
  scanf("%d",&n);
  int count=0;
  for(int i=0;i<n;i++)
  {
    scanf("%d %d",&a,&b);
    if(a==b)
    {
      count++;
      if(count>2)
      {
        printf("Yes");
        flag=1;
        break;
      }
    }else{
      count=0;
    }
    
  }
  if(flag==0)
  {
    if(count>2)
    {
      printf("Yes");
    }else{
      printf("No");
    }
  }
	return 0;
}
