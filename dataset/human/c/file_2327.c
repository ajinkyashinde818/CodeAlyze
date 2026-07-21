#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    long long int s;
    int n,k;
    
    scanf("%d %d %lld",&n,&k,&s);
    
    for(int i =0;i<n;i++){
        if(k > 0){
            printf("%lld",s);k--;
        }else if(s == 1000000000){
            printf("1");
        }else{
            printf("1000000000");
            }
        printf(" ");
    }
    printf("\n");
}
