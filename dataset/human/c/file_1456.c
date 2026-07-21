#include<stdio.h>
int main(){
    int N , i , count = 0 ;
    scanf("%d", &N);
    for(i = 0 ; i<2 ; i++){
        if(N%10 == 9){
            count++ ;
        }
         if(N/10 == 9){
            count++ ;
        }
    }
    if(count>0){
        printf("Yes");
    }else{
        printf("No");
    }
}
