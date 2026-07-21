#include<stdio.h>

int a[100001] = {};

int main(void){

  int p;
  int n;
  int k;


  p = 0;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);

    if(k <= a[i]){
       p++;
    }
  }

  printf("%d\n",p);

  return 0;

}
