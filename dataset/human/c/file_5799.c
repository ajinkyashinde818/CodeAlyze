#include<stdio.h>
int main(){
  int i,n;
  long num,min,calmax;
  scanf("%d",&n);
  scanf("%ld%ld",&min,&num);
  calmax=num-min;
  if(num<min)
    min=num;
  for(i=2;i<n;i++){
    scanf("%ld",&num);
    if(num-min>calmax)
      calmax=num-min;
    if(min>num)
      min=num;
  }
  printf("%d\n",calmax);
  return 0;
}
