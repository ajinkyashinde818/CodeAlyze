#include <stdio.h>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
    int a,b,c,d;
    scanf("%d%d%d%d", &a,&b,&c,&d);
    printf("%d\n",MAX(a*b,c*d));
    return 0;
}
