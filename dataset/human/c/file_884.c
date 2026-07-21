//div game
#include <stdio.h>
#include <math.h>

int main(void){
    unsigned long int n;
    unsigned long int sq_n;
    unsigned int i=2;
    unsigned long int cnt = 0;
    unsigned long int div;
    
    scanf("%lu",&n);
    sq_n = sqrt(n);

    if(n%i==0) {//i=2
        div = i;
        while(n%div==0){
            n/= div;
            div *= i;
            cnt ++;
        }
        while(n%i == 0) n/=i;
    }

    for(i = 3;i<=sq_n;i+=2){
        if(n%i==0) {
            div = i;
            while(n%div==0){
                n/= div;
                div *= i;
                cnt ++;
            }
            while(n%i == 0) n/=i;
        }
    }
    if(n != 1) cnt ++;
    printf("%lu",cnt);

    return 0;
}
