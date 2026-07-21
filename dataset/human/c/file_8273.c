/*
 * main.c
 *
 *  Created on: 2019/04/20
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, K;
    char S[11] = {0};
    int i = 0;
    scanf("%d", &N);
    scanf("%s",S);
    scanf("%d", &K);
    for(i = 0; i < N; i++) {
        char s = S[K-1];
        if(s == S[i]) {
            printf("%c",s);
        } else {
            printf("*");
        }
    }
    printf("\n");
    return 0;
}
