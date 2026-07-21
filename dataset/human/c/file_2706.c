#include <stdio.h>
                                                                                                
  
int main(void){
                                                                                                
   
    int k, s, x, y, z;
   
    int a = 0;
   
      
    scanf("%d %d", &k , &s);
   

    for( x = 0 ; x <= k ; x = x + 1 ){

        for( y = 0 ; y <= k ; y = y + 1 ){

            z = s - x - y;

            if( 0 <= z && z <= k ) a += 1;

            }

        }


    printf("%d\n", a);


    return 0;
                                                          
}
