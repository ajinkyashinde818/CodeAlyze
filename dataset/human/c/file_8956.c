#include <stdio.h>
int main(){
    long int i;
    int count;
    while(1){
        count=0;
        scanf("%ld",&i);
        if(i == 0){
            break;
        }
        while(1){
            if(i % 2 == 0){
                i/=2;
                count++;
            }
            if(i == 1){
                break;
            }
            else if(i % 2 == 1){
                i*=3;
                i++;
                count++;
            }
            if(i == 1){
                break;
            }
        }
        printf("%d\n",count);
    }
    return (0);
}
