#include <stdio.h>
int main(void){
    int A, B, K;
    int counter=1;
    int Kcount=0;
    int max;
    scanf("%d %d %d", &A, &B, &K);
    if (A>=B){
        max = A;
    }
    else{
        max = B;
    }
    counter =max;
    while(counter>0){
        if((A%counter ==0)&&(B%counter==0)){
            Kcount++;
            if(Kcount==K){
                printf("%d", counter);
            }
        }
        counter--;
    }
    return 0;
}
