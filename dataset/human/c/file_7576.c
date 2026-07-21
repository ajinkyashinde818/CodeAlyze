#include<stdio.h>
int main(){
    int x[10000];
    int i;
    int length=0;
    do{
        scanf("%d", &x[length]);
        length += 1;
    }while(x[length-1] != 0);
    for(i=0; i<length-1; i++){
        printf("Case %d: %d\n", i+1, x[i]);
    }
    return 0;
}
