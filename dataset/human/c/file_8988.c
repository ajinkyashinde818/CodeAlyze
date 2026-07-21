#include<stdio.h>
int main(void){
   int num, i, n, key;
   scanf("%d", &num);
   while ( num ) {
      key = 0;
      while ( num != 1) {
         if ( num % 2 == 0 ) num /= 2;
         else num = num * 3 + 1;
         key++;
      }
      printf("%d\n", key);
      scanf("%d", &num);
   }
   return 0;
}
