#include <stdio.h>

int main(void){
    int N,i,j,min;
    int result = 0;
    
    scanf( "%d" , &N );
    int num[N + 1];
    
    for( i = 0 ; i < N ; i++ ){
        scanf( "%d" , &num[i] );
    }
    
    result = num[1] - num[0];
    if( num[1] < num[0] ){
        min = num[1];
    }else{
        min = num[0];
    }
    //printf( "%d\n" , result );
    
    for( i = 2 ; i < N ; i++ ){
      if( num[i] < min ){
          min = num[i];
          //printf( "min%d\n" , min );
      }else if( result < ( num[i] - min ) ){
          //printf( "%d r%d - %d\n" , result,num[i] ,  min );
          result = num[i] - min;
          
      }
    }
    
    printf( "%d\n" , result );
}
