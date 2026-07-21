//    ABC073A.C

#include<stdio.h>


int main(void){
    
    int n, i, f = 0;

    scanf("%d", &n);
    while( 1 ) {
        if ( n == 0) break;
        if (n % 10 == 9) {
            f = 1;
            break;
        }
        n /= 10;
    }
    if (f == 1) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}
