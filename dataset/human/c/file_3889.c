#include <stdio.h>

int main(void)
{
  int A, B, K, i, temp, count = 0, num[10000] = {0};
  scanf("%d %d %d", &A, &B, &K);
  
  if(B > A){
    temp = B;
    B = A;
    A = temp;
  }
  
  for(i = B; 1 <= i; i--){
   if((A % i == 0)&&(B % i == 0)){
     num[count] = i;
     count++;
   }
  }

  printf("%d", num[K-1]);
         
  return 0;
}
