#include <stdio.h>
int main(void){
   
    int K,P,N;

    scanf ("%d",&N);

    while (N > 0){

        scanf ("%d",&K);
        scanf ("%d",&P);

        if (K % P == 0)
            printf ("%d\n",P);
        else
            printf ("%d\n",K % P);
        N--;
    }

    return 0;
}
