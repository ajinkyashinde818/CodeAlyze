#include <stdio.h>

int cnt ;
char s[3] ;

int main(void){
    
    scanf ("%s",s) ;
    
    if ( s[0]=='a' || s[1]=='a' || s[2]=='a' ){
        cnt++ ;
    }
    
    if ( s[0]=='b' || s[1]=='b' || s[2]=='b' ){
        cnt++ ;
    }
    
    if ( s[0]=='c' || s[1]=='c' || s[2]=='c' ){
        cnt++ ;
    }
    
    if ( cnt==3 ){
        printf ("Yes\n") ;
    } else {
        printf ("No\n") ;
    }

    return 0 ;
}
