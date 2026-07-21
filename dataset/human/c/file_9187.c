#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int k;
  scanf("%d",&k);
  int d[n];
  int i;
  int a=0;
  for(i=0;i<n;i++){ scanf("%d",&d[i]);if(d[i]>=k){a=a+1;}}
  printf("%d",a); return 0;
}
