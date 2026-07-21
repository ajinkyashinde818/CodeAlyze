#include<stdio.h>

long int calc_lcm(long int a, long int b){
    long int temp = 0;
    long int x;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    x = a * b;
    temp = a % b;
    while(temp != 0){
        a = b;
        b = temp;
        temp = a % b;
    }
    return x / b;
}

int main(void){
    long int a, b;
    scanf("%ld""%ld", &a, &b);
    printf("%ld\n", calc_lcm(a, b));
    return 0;

}
