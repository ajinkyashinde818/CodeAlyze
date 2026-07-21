#include<stdio.h>

int main(void)
{
  int k,n,i;
  int house[1000000];
  int max = 0;
  
  scanf("%d",&k);
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&house[i]);
  
  for(i = 0;i < n;i++){
    if(max < house[i+1]-house[i]){
      max = house[i+1]-house[i];
    }
  }
  
  if(max < k + house[0] - house[n-1])
    max = k + house[0] - house[n-1];
  
  printf("%d\n",k-max);
  
  return 0;
}
