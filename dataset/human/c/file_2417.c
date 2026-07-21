#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                                                                                                
  
int comp(const void *a, const void *b){

    return strcmp( ( char * )a , ( char * )b );

    }


int main(void){
                                                                                                
   
    int a, b, c;
   
    char s[5];
   
      
    scanf("%s", s );
   

    qsort( s, 3, sizeof(char), comp );
   

    if( s[0] == 'a' && s[1] == 'b' && s[2] == 'c' ){

        printf("Yes\n");

        return 0;

        }

    else printf("No\n");


    return 0;
                                                          
}
