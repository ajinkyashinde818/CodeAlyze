#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long int input1 = 0;
    long int input2 = 0;
    scanf("%ld", &input1);
    scanf("%ld", &input2);
    long x = input1 * input2;

    if(input1<input2){
        long tmp = input1;
        input1 = input2;
        input2 = tmp;
    }

    long r = input1 % input2;
    while(r!=0){
        input1 = input2;
        input2 = r;
        r = input1 % input2;
    }
    long result = x/input2;

    printf("%ld\n", result);
    return 0;
}
