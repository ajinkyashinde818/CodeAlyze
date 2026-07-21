#include<stdio.h>
#include<math.h>

#define N 200000

int main(void){
  int k, n, a[N], dis, maxDis=0;
  scanf("%d %d",&k,&n);
  for(int i=0; i<n; i++)
    scanf("%d",&a[i]);
  
  for(int i=0; i<n-1; i++){
    dis = a[i+1]-a[i];
    if(maxDis < dis)
      maxDis = dis;
  }
  dis = k - a[n-1] + a[0];
  if(maxDis < dis)
      maxDis = dis;
  
  printf("%d",k-maxDis);
  return 0;
}
