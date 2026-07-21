#include <stdio.h>
#include<string.h>

int main(void) {
  int n,count=0;
  scanf("%d",&n);
  int a[n],b[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d %d",&a[i],&b[i]);

  }
  int flag=0;
  for(int i=0;i<n-2;i++)
  {
    if((a[i]==b[i])&&(a[i+1]==b[i+1])&&(a[i+2]==b[i+2]))
    {
      flag=1;
      break;
    }

  }
  if(flag==1)
  printf("Yes\n");
  else
  printf("No\n");
  return 0;
}
