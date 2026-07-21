#include <stdio.h>
#include <math.h>

int main(void){
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int count = 0;
    int i;
    if(a<b)i = a;
    else i = b;
    while(1){
        if(a%i == 0 && b%i == 0)count++;
        if(count == k)break;
        i--;
    }
    printf("%d\n", i);
    return 0;
}
