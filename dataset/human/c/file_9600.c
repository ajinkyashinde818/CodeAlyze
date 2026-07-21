#include <stdio.h>

int main(void){
  int n,d,x,c,cn=0,b;
  scanf("%d %d %d",&n,&d,&x);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i =0;i < n;i++){
    c = a[i];
    b=1;
    while(c < d){
      c = b * a[i] + 1;
      b++;
      if(c <= d){
      cn++;
      }
      //printf("> %d\n",c);
    }
    //printf("%d：%d\n",i+1,cn);
  }
  printf("%d\n",cn+x+n);
  return 0;
}
