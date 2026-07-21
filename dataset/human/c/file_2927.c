#include <stdio.h>

int main(void)
{
 int K, S;
 int x, y, z;
 int cnt = 0;
 
 
 scanf("%d %d", &K, &S);
 
 for( x = 0; x <= K; x++ ){
   for( y = 0; y <= x; y++ ){
     for( z = 0; z <= y; z++ ){
       if( x + y + z == S ){
         if( x==y || y==z || z==x ){
           if( x==y && y==z ) cnt++;
           else{              cnt+=3;}
         }
         else{                cnt+=6;}         
       }
     }
   }
 }
 
 printf("%d\n", cnt);
 

 return 0;
 
}
