#include<stdio.h>
#define N 200000

int main(void){
  int data[N],len,i,j,max,min;

  scanf("%d",&len);
  for(i=0;i<len;i++) scanf("%d",&data[i]);

  min=data[0];
  max=data[1]-data[0];

  for(j=1;j<len;j++){
    if(max<data[j]-min) max=data[j]-min;
    if(min>data[j]) min=data[j];
  }

  printf("%d\n",max);
  return 0;
}
