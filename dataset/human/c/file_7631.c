#include <stdio.h>

#define INPUT_NUMBER 3

int main(void){
    int num[10000];
    int not_zero=1;
    int i=0;

    while(not_zero){
        scanf("%d",&num[i]);
        if(num[i]==0){
            not_zero=0;
        }
        i++;
    }

    for(int h=0;h<i-1;h++){
        printf("Case %d: %d\n",h+1,num[h]);
    }

    return 0;
}
