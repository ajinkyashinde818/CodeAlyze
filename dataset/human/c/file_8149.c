#include<stdio.h>

int main(void) {
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);

  int A,B;
  A = a*b;
  B = c*d;
  if(A>B){
    printf("%d\n",A);
  } else {
    printf("%d\n",B);
  }

  return 0;
}
