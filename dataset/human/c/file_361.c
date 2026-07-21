#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,R;
    int ans;

    scanf("%d",&N);
    scanf("%d",&R);

    if(N>=10){
        printf("%d",R);
    }else{
        printf("%d",R+(100*(10-N)));
    }

    return 0;
}
