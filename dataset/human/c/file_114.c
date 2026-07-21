/*
 * main.c
 *
 *  Created on: 2019/05/11
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int R = 0, G = 0, B = 0, N = 0;
    int r,g,b, ans = 0;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for(r = 0; r <= N; r++) {
        for(g = 0; g <= N; g++) {
            int temp = (N - (r*R) - (g*G));
            b = temp/B;
            if(((temp - b*B) == 0) && (b >= 0)) {
                //printf("N=%d,r=%d,g=%d,b=%d\n",N,r*R,g*G,b*B);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
