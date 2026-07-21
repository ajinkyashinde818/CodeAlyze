#include <stdio.h>

int main(){

  int t[200010];
  int n,i,max=-100000000000,min,tmp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&t[i]);
  }
  min=t[0];
  for(i=1;i<n;i++){
    tmp=t[i]-min;
    if(max<tmp) max=tmp;
    if(t[i]<min) min=t[i];
  }
  printf("%d\n",max);
  return 0;
}
