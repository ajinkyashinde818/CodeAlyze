#include<stdio.h>

int main(void){

  int n=0;
  int d=0, x=0;
  int sum=0;
  int k=0;
  int i=0;
  int a[100]={0};

  scanf("%d", &n);
  scanf("%d %d", &d, &x);
  for(i=0; i<n; i++){
    scanf("%d", a+i);
  }

  for(i=0; i<n; i++){
    k=0;
    while(k*a[i]+1 <= d){
      sum=sum+1;
      k++;
    }
  }

  printf("%d\n", sum+x);

  return 0;
}
