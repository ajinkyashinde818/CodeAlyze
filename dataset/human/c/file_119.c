#include <stdio.h>

int main()
{
    int R,G,B,N,i,j,k,m1,m2,m3,n2,n3,time=0;
    scanf("%d",&R);
    scanf("%d",&G);
    scanf("%d",&B);
    scanf("%d",&N);

    if (R<=G && G<=B) {
        m1 = R;
        m2 = G;
        m3 = B;
    }
    if (R<=B && B<=G) {
        m1 = R;
        m2 = B;
        m3 = G;
    }
    if (G<=R && R<=B) {
        m1 = G;
        m2 = R;
        m3 = B;
    }
    if (G<=B && B<=R) {
        m1 = G;
        m2 = B;
        m3 = R;
    }
    if (B<=R && R<=G) {
        m1 = B;
        m2 = R;
        m3 = G;
    }
    if (B<=G && G<=R) {
        m1 = B;
        m2 = G;
        m3 = R;
    }

    n3 = N/m3;
    
    for(i=0;i<=n3;i++){

        n2 = (N-i*m3)/m2;

        for(j=0;j<=n2;j++){

            if((N-i*m3-j*m2)%m1 == 0){
                time++;
            }
        }
    }
    printf("%d",time);
    return 0;
}
