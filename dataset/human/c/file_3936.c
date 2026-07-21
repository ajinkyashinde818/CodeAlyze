#include <stdio.h>
int main(void){
    int A,B,K;
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&K);
    
    int Max = A,counter = 0;
    if(A>B) Max = B;
    
    for(int i = Max;i > 0;i--){
        if(A%i == 0 && B%i == 0) counter++;
        if(counter == K){
            printf("%d",i);
            return 0;
        }
    }
    
    return 0;
    
}
