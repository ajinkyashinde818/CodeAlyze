#include<stdio.h>

int main(){
  int a[100],n,d,x,i;
  scanf("%d",&n);
  scanf("%d %d",&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    x+=1+(d-1)/a[i];
  }
  printf("%d\n",x);
}
