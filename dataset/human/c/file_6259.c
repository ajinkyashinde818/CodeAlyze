#include<stdio.h>

int main(){
  int n, a, i, s;
  int min=1000*1000*1000;
  
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &a);
    if(i==0)  min=a;
    if(i==1) s=a-min;
    if(a-min>s) s=a-min;
    if(min>a) min=a;
  }
  
  printf("%d\n", s);
  
  return 0;
}
