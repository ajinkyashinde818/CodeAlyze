#include <stdio.h>
#include <string.h>
                                                                                                
  
int main(void){
                                                                                                
   

    char s[101];

    char t[101];

    int i,j;

    char tm;
   
      
    scanf("%s", s );
   
    scanf("%s", t );
   


    for( i = 0 ; i <= strlen(s) - 1 ; i = i + 1 ){

        for( j = i + 1 ; j <= strlen(s) - 1 ; j = j + 1 ){        

             if( s[j] < s[i] ){

                 tm = s[j];

                 s[j] = s[i];

                 s[i] = tm;

                 }

              }

         }


    for( i = 0 ; i <= strlen(t) - 1 ; i = i + 1 ){

         for( j = i + 1 ; j <= strlen(t) - 1 ; j = j + 1 ){        

             if( t[j] > t[i] ){

                 tm = t[i];

                 t[i] = t[j];

                 t[j] = tm;

                 }

              }

         }
    
    
    if( strcmp( s, t ) >= 0 ) printf("No\n");

    else printf("Yes\n");


    return 0;
                                                          
}
