#include <stdio.h>

int main(void){
        int k[1000], p[1000];
        int n, winner;
        int i;

        scanf("%d", &n);

        for( i=0 ; i<n ; i++ )
                scanf("%d %d", &k[i], &p[i]);

        for( i=0 ; i<n ; i++ ){

                if( (k[i]%p[i])==0 )
                        winner = p[i];

                else
                        winner = (k[i]%p[i]);

                printf("%d\n", winner);
        }

        return 0;
}
