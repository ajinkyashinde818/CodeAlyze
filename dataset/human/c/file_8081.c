#include <stdio.h>
                                                                                                
  
int main(void){
                                                                                                
   
    long long a, b, c, d, m;
         
   
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d );
   

    m = a * b;

    if( m < c * d ){

        m = c * d;

        printf("%lld\n", m );

        return 0;

        }

    else{

          printf("%lld\n", m );

          return 0;

          }

    return 0;
                                                          
}
