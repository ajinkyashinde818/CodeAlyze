#include <stdio.h>

int main(void)
{
  int k,n;
  scanf("%d",&k);
  scanf("%d",&n);
  
  int id[n];
  int dist[n];
  for(int i=0; i<n; i++){
    scanf("%d",&id[i]);
    dist[i]=0;
  }
  
  for(int i=0; i<(n-1); i++){
    dist[i]=id[i+1]-id[i];
  }
  dist[n-1]=(k-id[n-1])+id[0];
  
  int calc=0,max=0;
  for(int i=0; i<n; i++){
    calc += dist[i];
    if(max<dist[i]) max=dist[i];
  }
  
  printf("%d",calc-max);
  
  return 0;
}
