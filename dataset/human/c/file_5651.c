#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    long long x,ans;
    scanf ("%lld",&x);
    if (x%11==0){
        printf ("%lld",(x/11)*2);
    } else if (x%11<=6){
        printf ("%lld",ans=(x/11)*2+1);
    } else {
        printf ("%lld",(x/11)*2+2);
    }
	return 0 ;
}
