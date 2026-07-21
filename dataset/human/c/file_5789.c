#include<stdio.h>
#define N 200000

int main(){
  int n,i,r[N];
  int min,max;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&r[i]);
  min = r[0];
  max = r[1]-r[0];
  for(i=1;i<n;i++){
    if(max<(r[i]-min)) max = r[i]-min;
    if(min>r[i]) min = r[i];
  }
  printf("%d\n",max);
  return 0;
}
