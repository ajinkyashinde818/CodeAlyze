#include <stdio.h>

int yu(int a, int b){
 int r, tmp;
 if(a < b){
     tmp = a;
     a = b;
     b = tmp;
 }
 r = a % b;
 while(r != 0){
     a = b;
     b = r;
     r = a % b;
 }

 return b;

}

int main(void){
    int a, b, g;
    scanf("%d%d", &a, &b);

    g = yu(a, b);

    long aa;
    aa = a / g;
    long bb;
    bb = b / g;

    long l;
    l = aa * bb * g;

    printf("%lld", l);

    return 0;
}
