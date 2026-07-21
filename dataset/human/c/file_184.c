#include<stdio.h>

#define	LIM		(100000+1)
#define MIN(NUM,NUM2)	((((long)NUM)<((long)NUM2))?(NUM):(NUM2))
#define	ABS(NUM)		(((NUM)>0)?(NUM):(-1*(NUM)))

int main(void)
{
  long n, a[LIM]={}, ans=0;
  int i;
  long min = 0x7FFFFFFF;
  int under_zero = 0;
  
  scanf("%ld", &n);

  for(i=0; i<n; i++){
	scanf("%ld", &a[i]);
    ans += ABS(a[i]);
    min = MIN(min, ABS(a[i]));
    if(a[i]<0)under_zero++;
  }
  
  if(under_zero&(int)0x01)
    ans -= min<<= 1;
    
  printf("%ld\n", ans);
  
  return 0;
}
