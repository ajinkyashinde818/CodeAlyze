#include<stdio.h>

int main (void)
{
  int A , B , K;
  scanf("%d %d %d", &A , &B , &K);
  int keep[50];

  int count = 0;
  for(int i = 1 ; i <= 100 ; i++){
    if(A % i == 0 && B % i == 0){
      keep[count] = i;
      count++;
    }
  }

  printf("%d",keep[count - K]);

return 0;
}
