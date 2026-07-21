#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n,i,j;
  scanf("%d",&n);
  int a[n];

  for(i=0;i<n;i++){
    //printf("inout\n");
    scanf("%d",&a[i]);
  }

  int max=-999999999;
  int min=1000000000;
  /*for(i=n-1;i>0;i--){
    for(j=0;j<i;j++){
      //printf("%d,%d,%d\n",i,j,a[i]-a[j]);
      if(max<a[i]-a[j]){
        max=a[i]-a[j];
      }
    }
  }*/
  for(i=1;i<n;i++){
    //printf("%d,\n",a[i]);
    if(min>a[i-1]){
      min=a[i-1];
    }
    //printf("%d,,\n",min);
    if(max<a[i]-min){
      //printf("%d\n",i);
      max=a[i]-min;
    }
  }

  printf("%d\n",max);
}
