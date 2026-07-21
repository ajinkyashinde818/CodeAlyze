#include<stdio.h>
int main(void)
{
int A, B, C ,D;

scanf("%d %d %d %d", &A, &B, &C, &D);
int X = A * B;
int Y = C * D;
  if(X > Y){
    printf("%d", X);
  } else if(X < Y){
    printf("%d", Y);
  } else if(X == Y){
    printf("%d", X);
  }
  return 0;
}
