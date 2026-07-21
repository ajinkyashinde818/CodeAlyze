#include<stdio.h>
int main(void){
   int n, R[200000], max, key, i, l, key2;
   scanf("%d", &n);
   for ( i = 0; i < n; i++ ) {
      scanf("%d", &R[i]);
   }
   max = R[1] - R[0]; /*printf("\n%d\n", max);*/
   for ( l = 1; l < n; l++ ) {
      key = R[l] - R[0];
      if ( max < key ) { max = key; /*printf("%d\n", key);*/ }
   }
   key2 = 0;
   for ( i = 1; i < n; i++ ) {
      if ( R[i] < R[key2] ) {
         for ( l = 1; l < n - i; l++ ) {
            key = R[i + l] - R[i];
            if ( max < key ) { max = key; /*printf("%d\n", key);*/ }
            key2 = i;
         }
      }
   }
   printf("%d\n", max);
   return 0;
}
