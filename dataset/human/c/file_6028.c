#include <stdio.h>
int main(){
  int num,max,i,min;
  scanf("%d",&num);
  int a[num];
  for(i = 0 ;i<num ; i++){
    scanf("%d",&a[i]);
  }
  max = a[1] -a[0];
  min = a[0];
  for(i=1;i<=num-1;i++){
    if(max <a[i]-min) max = a[i]-min;
    if(min>a[i]) min = a[i];
   
}
  printf("%d\n",max);
  return 0;
}
