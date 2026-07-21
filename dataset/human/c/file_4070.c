#include <stdio.h>
int main(void)
{
  int a,b,k,max,ans,count,i;
  ans = 0;
  count =0;
  scanf("%d",&a);	
  scanf("%d",&b);	
  scanf("%d",&k);	
  max = a;
  if (b>a)	max = b;
  i = max;
  do {
	if (a % i==0 && b % i ==0)
		count = count + 1, ans = i;
	i = i -1;

  } while (count<k);
  printf("%d",ans);
  return 0;
}
