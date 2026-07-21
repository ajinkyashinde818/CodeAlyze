#include <stdio.h>

int main(void){

    static int n,d,x ;
    scanf ("%d%d%d",&n,&d,&x) ;
    
    for (int i=0; i<n; i++){
        
        int a[i] ;
        scanf ("%d",&a[i]) ;
        
        x += ((d-1)/a[i])+1 ;
        
    }

    printf ("%d\n",x) ;
    
    return 0 ;
}
