#include<stdio.h>
int main()
{
  int x[10000],j, count=0;
int i;

  for(i=1; i<=10000; i++) {
    scanf("%d",&x[i]);
    if(x[i]==0){ break;
    }
    count++;
  }

  for(i=1; i<=count; i++) {
    printf("Case %d: %d\n" ,i ,x[i]);
  }

  return 0;
}
