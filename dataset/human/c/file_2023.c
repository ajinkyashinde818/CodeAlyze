#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int min(int a, int b) { return a < b ? a : b; }
int main(){
    int a,b,c,poison;
    scanf("%d %d %d",&a,&b,&c);
    poison=min(a+b+1,c);
    printf("%d",b+poison);
    return 0;
}
