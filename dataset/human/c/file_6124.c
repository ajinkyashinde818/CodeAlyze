#include<stdio.h>
#include<math.h>

int main(void){
  int n,min,max;
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }

  min = a[0];
  max = a[1]-a[0];

  for(int i=1; i<n; i++){
    if((a[i]-min)>max){
      max=a[i]-min;
    }
    if(min>a[i]){
      min = a[i];
    }
  }

  printf("%d\n", max);

  return 0;

}
