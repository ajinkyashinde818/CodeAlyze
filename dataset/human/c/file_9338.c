/* ABC142-B
   Takatan */

#include<stdio.h>
int main(void){
    int number, limit, height, count, i;
    count = 0;

    scanf( "%d %d" , &number, &limit);
    for(i=0; i < number; i++){
        scanf( "%d" , &height);
        if(height>=limit){ /* 乗車可能な時 */
            count++; /* 加算 */
        }
    }
    printf( "%d\n" , count);
    return 0;
}
