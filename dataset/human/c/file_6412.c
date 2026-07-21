#include<stdio.h>

#define SIZE 200001
#define MIN -1000000000

int main(){
  int i,j;
  int max=MIN,min;
  int a[SIZE];

  while(scanf("%d",&a[i]) != EOF){
    i++;
  }

  min=a[1];
  for(i=2;i<=a[0];i++){
    if(max<a[i]-min)
      max=a[i]-min;
    if(min>a[i])
      min=a[i];
  }
  printf("%d\n",max);

  return 0;
}
