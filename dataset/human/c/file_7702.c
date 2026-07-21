#include <stdio.h>
int main(void)
{
  int i=0;
  int a[100000]={0};
  int f;

  while(1) {
	scanf("%d",&a[i]);

	if (a[i]==0)
	  break;
	i++;
  }

  f=i;

  for (i=0; i<f; i++) {
	printf("Case %d: %d\n",i+1,a[i]);
  }

  return 0;
}
