#include<stdio.h>

int main(void){

int R, G, B, N, r, g;
int count = 0;

scanf("%d", &R);
scanf("%d", &G);
scanf("%d", &B);
scanf("%d", &N);


for(r = 0; r <= N/R; r++){
    for(g = 0; g <= (N-R*r)/G; g++){
        if((N - R*r - G*g) % B == 0)
        count += 1;
    }
}


printf("%d\n", count);


return 0;
}
