#include<stdio.h>

int main()
{
  int i,n[10000],count=1,temp;

  while(1){
    scanf("%d",&n[count]);
    if(n[count]==0)
      break;
    count++;
  }

  for(i=1;i<count;i++)
    printf("Case %d: %d\n",i,n[i]);
  
  return 0;
}
