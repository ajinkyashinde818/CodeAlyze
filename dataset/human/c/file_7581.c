#include <stdio.h>

int main(void){
    int i[10000];
    int l = 1;
    int t = 1;
    int e1, e2;

    for( e1 = 0; e1 == 0; l++ ) {
        scanf("%d", &i[l]);
        if( i[l] == 0 ) e1 = 1;
    }
    for( e2 = 0; e2 == 0; t++ ){
        if ( t == l - 2 ) e2 = 1;
        printf("Case %d: %d\n", t, i[t]);
    }
    return 0;
}
