#include <stdio.h>

int main(void){
        long long int X,Y,r,z,tmp;

        scanf("%lld %lld ",&X,&Y);

        z = X * Y;

        if (X < Y){
                tmp = X;
                X = Y;
                Y = tmp;
        }

        r = X % Y;
        while (r != 0){
                X = Y;
                Y = r;
                r = X % Y;
        }

        printf("%lld\n", z / Y);

        return 0;
}
