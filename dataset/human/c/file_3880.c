#include <stdio.h>

int main(){
    int a, b, k;
    int i, j = 0;

    scanf("%d %d %d",&a,&b,&k);

    i = (a < b) ? a : b;
    while(1){
        if(a%i == 0 && b%i == 0) { 
            j++;
            if(k == j) {
                printf("%d", i);
                break;
            }
        }
        i--;
    }
    
}
