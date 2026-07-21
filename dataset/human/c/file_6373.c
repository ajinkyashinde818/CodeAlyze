#include <stdio.h>

int main ( void ) {
    
    int Max_number = 0;
    int Arr[2] = {};
    int min = 0;
    int output = 0;
    int i = 0;
    int j = 0;
    
    scanf ( "%d", &Max_number );
    
    scanf ( "%d", &Arr[0] );
    
    scanf ( "%d", &Arr[1] );
    
    output = Arr[1] - Arr[0];
    
    if ( Arr[0] < Arr[1] ) {
        min = Arr[0];
    } else {
        min = Arr[1];
    }
    
    for ( i = 2; i < Max_number; i++ ) {
        scanf ( "%d", &Arr[0] );
        if ( output < (Arr[0] - min) ) {
            output = Arr[0] - min;
        }
        
        if ( min > Arr[0] ) {
            
            min = Arr[0];
        
        }
    }
    
    printf( "%d\n", output );
    
    return 0;
    
}
