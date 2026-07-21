#include <stdio.h>
#define MAX 100000
int main()
{
	int n,num=0;
	int a[MAX];
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	  i=1;
	  while(1)
	  {
  		num++;
  		if(a[i]==2)
  		{
		  	printf("%d",num);
		  	break;
		  }
		  i=a[i];
		  if(num>n)
		  {
  			printf("-1\n");
  			break;
  		}
  	}
	
	

}
