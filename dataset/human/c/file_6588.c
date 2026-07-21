#include <stdio.h>
#include <stdlib.h>
int main(void){

    int num;
    int max,min;
    int n;
    int i;

    max = -1000000000;


    scanf("%d",&num);
    scanf("%d",&min);

    for( i = 1 ; i < num ; i++ ){

      scanf("%d",&n);

      if( max < n-min )
        max = n-min;

      if( min > n )
        min = n;

    }

    printf("%d\n",max);


    return 0;

}
