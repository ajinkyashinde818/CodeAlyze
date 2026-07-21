#include<stdio.h>
#include<stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int main(){
    int A , B , K ;
    scanf("%d%d%d",&A,&B,&K) ;
    int arr[100] ;
    int x = MIN(A,B) ;int i, k = 0;
    for( i = x ; i>=1 ; i--){
        if(A % i == 0 && B % i == 0){
            arr[k] = i ;
            k++ ;
        }
    }
    
    printf("%d",arr[K-1]);
}
