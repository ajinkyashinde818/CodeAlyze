#include <stdio.h>
#define MAX(x,y)	((x)>(y)?(x):(y))
int main(){
  int k,n,max=0,a[200000+1]={0};
  scanf("%d%d",&k,&n);
  for(int i=0; i<n; i++){
    scanf("%d",&a[i]);
    if(i){ max = MAX( max, (a[i] - a[i-1]) ); }
  }
  max = MAX( max, (k-a[n-1]+a[0]) );
  printf("%d", k-max);
  return 0;
}
