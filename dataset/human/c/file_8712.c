#include <stdio.h>

int main (void)
{
  int n;
  scanf("%d",&n);
  
  int a[n];
  for(int i = 0;i < n;i ++){
    scanf("%d",&a[i]);
  }
   int i = 0;
  for(int j = 0;j < n;j ++){
    int s = a[i]-1;
        i = s;
    if(i==1){
      printf("%d\n",j+1);
      return 0;
    }}
  
  printf("-1");
  return 0;
}
