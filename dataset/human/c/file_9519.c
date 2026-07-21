#include <stdio.h>
#include <math.h>
int main (void){
        int N,D,X,A[100],ans=0;
        for (int i = 0; i < 100; i++) {
                A[i]=0;
        }
        scanf("%d",&N);
        scanf("%d",&D);
        scanf("%d",&X);
        for (int i = 0; i < N; i++) {
                scanf("%d",&A[i]);
        }
        for (int i = 0; i < N; i++) {
                ans+=((D-1)/A[i])+1;
        }
        ans+=X;
        printf("%d\n",ans );
        return 0;

}
