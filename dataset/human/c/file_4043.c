#include <stdio.h>

int main(){
    int first, second, largest;
    scanf("%d %d %d", &first, &second, &largest);
    int big, small;

    if(first>second){
        big = first;
        small = second;
    }
    else{
        int tmp;
        tmp = first;
        big = second;
        small = tmp;
    }
    //printf("big is %d, small is %d", big, small);
    int i, count=0;
    for(i=small; i>0; i--){
        if(big%i==0 && small%i==0){
            count++;
            if(count == largest){
                printf("%d", i);
                break;
            }
        }
    }
}
