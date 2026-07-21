#include <stdio.h>
int main(void){
    int n , i , j , r[200001] ;
    
    scanf("%d" , &n) ;
    
    for(i = 0 ; i < n ; i++){
        scanf("%d" , &r[i]) ;
    }
    int maxv = r[1] - r[0] , min = r[0] ;
    
    for(i = 1 ; i < n ; i++){
        if(r[i] - min > maxv){
            maxv = r[i] - min ;
        }
        if(r[i] < min){
            min = r[i] ;
        }
    }
    printf("%d\n" , maxv) ; 
    return 0 ;
}
