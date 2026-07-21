/*
  AOJ #0328
  title:Metal Recycling
  @kankichi573
 */
#include <stdio.h>
#include <string.h>

int a,b,n,bok[200017];

main()
{
  int i;
  scanf("%d",&n);
  memset(bok,0,sizeof(bok));
  for(i=0;i<n;i++)
    {
      scanf("%d %d",&a,&b);
      bok[a+b]++;
    }
  for(i=0;i<200017;i++)
    {
      bok[i+1] += bok[i]/2;
      bok[i]   &= 1;
    }
  for(i=0;i<200017;i++)
    if(bok[i])
      printf("%d 0\n",i);
  
  return(0);
}
