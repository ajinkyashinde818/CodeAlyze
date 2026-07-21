#include <stdio.h>

int main(){
    int a,b,c;
    int i = 101, count = 0;

    scanf("%d%d%d" ,&a,&b,&c);

    while(1){
        i--;
        if(a % i == 0 && b % i == 0){
            count++;
        }
        if(count == c){
            break;
        }
    }
    printf("%d\n" ,i);

    return 0;  
}
