#include<stdio.h>
#include<string.h>

int main()
{
  int i,n,d1[101],d2[101];
  
  scanf("%d", &n);
 
  for (i=1;i<=n;i++)
  {
  	scanf("%d %d",&d1[i],&d2[i]);
    //printf("%d %d\n",d1[i],d2[i]);
  }
  
  for (i=1;i<=n;i++)
  {
  	if (d1[i]==d2[i] && d1[i+1]==d2[i+1] && d1[i+2]==d2[i+2])
    {
    	printf("Yes");
      	return 0;
    }  
  }
   printf("No");
 
  return 0;
}
