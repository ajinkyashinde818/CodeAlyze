#include<stdio.h>

#define MAX 200000

int main(){
  int i,j,l,max,min,a[MAX];
  

  scanf("%d",&l);

  for(i = 0; i < l; i++)
    scanf("%d",&a[i]);

  max = a[1] - a[0];
  min = a[0];
  
  for(i = 1; i < l; i++){
	max = (max < (a[i] - min)) ? (a[i] - min) : max;
	min = (min > a[i]) ? a[i] : min;
  }
  printf("%d\n",max);

  return 0;
}
