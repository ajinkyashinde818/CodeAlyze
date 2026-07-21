#include<stdio.h>

int main()
{
    int sum;
    int count;
    int in_s, in_k;
    int z;

   count = 0;

   scanf("%d %d",  &in_k, &in_s);
   // printf("s = %d k = %d \n", in_k, in_s);

 for (int i = 0; i <= in_k; i++) {
   for(int j = 0; j <= in_k; j++) {
     // for (int k = 0; k <= in_k; k++) {
     //    if (i <= in_k && j <= in_k && k <= in_k) {
     //     sum = i + j + k;
     //     printf("x = %d   y = %d   z = %d  sum = %d\n", i, j, k, sum);
     //     if (sum == in_s) {
     //       count++;
     //     }
     z = in_s - i -j;
     if (z >= 0 && z <= in_k) {
         count++;
        }
      }
    }
  printf("%d\n", count);
}
