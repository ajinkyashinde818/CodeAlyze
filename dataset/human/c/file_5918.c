#include<stdio.h>
int sosuch();

int main(){
  int a,n,min,sa,i;
  scanf("%d",&n);
  scanf("%d",&a);
  min=a;
  scanf("%d",&a);
  sa = a-min;
  if(min>a) min=a;
  for(i=0;i<n-2;i++){
    scanf("%d",&a);
    if(a-min > sa) sa = a-min;
    if(min>a) min=a;
  }
  printf("%d\n",sa);
return 0;
}
