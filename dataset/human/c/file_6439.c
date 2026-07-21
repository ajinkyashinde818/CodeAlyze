#include<stdio.h>

int main(void){
    int i;
    int max = -2147483648;
    scanf("%d\n", &i);
    int min = 0;
    scanf("%d\n", &min);
    while((scanf("%d\n", &i)) != EOF){
        if((i - min) > max) max = i - min;
        if(i < min) min = i;
    }
    printf("%d\n", max);
    return 0;
}
