#include <stdio.h>

int a,b ;
char x[2],y[2] ;

int main(void){
    
    scanf ("%s%s",x,y) ;
    
    if ( x[0]=='A' ){
        a = 10 ;
    } else if ( x[0]=='B' ){
        a = 11 ;
    } else if ( x[0]=='C' ){
        a = 12 ;
    } else if ( x[0]=='D' ){
        a = 13 ;
    } else if ( x[0]=='E' ){
        a = 14 ;
    } else if ( x[0]=='F' ){
        a = 15;
    } else {
    }
    
    if ( y[0]=='A' ){
        b = 10 ;
    } else if ( y[0]=='B' ){
        b = 11 ;
    } else if ( y[0]=='C' ){
        b = 12 ;
    } else if ( y[0]=='D' ){
        b = 13 ;
    } else if ( y[0]=='E' ){
        b = 14 ;
    } else if ( y[0]=='F' ){
        b = 15;
    } else {
    }
    
    if ( a<b ){
        printf ("<\n") ;
    } else if (a==b) {
        printf ("=\n") ;
    } else if ( a>b ){
        printf (">\n") ;
    } else{
    }
    
    return 0 ;
    
}
