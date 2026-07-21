/* ABC140-B
   Takatan */

#include<stdio.h>
#include<stdlib.h>
int main(void){
    int number, *meal, *happy, sum, i;
    sum = 0;

    scanf( "%d" , &number);
    meal = malloc(sizeof(int) * number);
    happy = malloc(sizeof(int) * number);
    for(i=0; i < number; i++){
        scanf( "%d" , &meal[i]);
    }
    for(i=0; i < number; i++){
        scanf( "%d" , &happy[i]);
        sum += happy[i]; /* 全ての料理の満足度を加算 */
    }
    for(i=0; i < number-1; i++){
        scanf( "%d" , &happy[i]);
    }

    for(i=1; i < number; i++){
        if(meal[i-1]==meal[i]-1){ /* 料理の番号が連続している時 */
            sum += happy[meal[i]-2]; /* 満足度の加算 */
        }
    }

    printf( "%d\n" , sum);
    return 0;
}
