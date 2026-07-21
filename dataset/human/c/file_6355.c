#include<stdio.h>

int main(){

  int i, j, n, result=0;

  scanf("%d", &n);

  int a[n];

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  int min=a[0];
  
  result=a[1]-min;

  for(i=1;i<n;i++){

    if(a[i]-min>result) result=a[i]-min;

    if(a[i]<min) min=a[i];

  }

  printf("%d\n",result);

  return 0;

}
