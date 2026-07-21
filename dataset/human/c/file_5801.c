#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,min,max=0,i;
  int *b;
  scanf("%d",&a);
  b=(int *)malloc(sizeof(int) * a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  min=b[0];
  max=b[1]-b[0];
  for(i=1;i<a;i++){
    if(max<b[i]-min)max=b[i]-min;
    if(min>b[i])min=b[i];     
  }
  printf("%d\n",max);
  return 0;
}
